#include "calibratewindow.h"
#include "ui_calibratewindow.h"
#include <cv.h>
#include <QSettings>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

#include <QMessageBox>
#include <QDebug>

calibratewindow::calibratewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calibratewindow)
{
    ui->setupUi(this);
}

calibratewindow::~calibratewindow()
{
    delete ui;
}


double calibratewindow::shortestDistance(cv::Vec4i endPoints, cv::Vec2d ellipseCenter)
{
    // The purpose of this call is to determine the shortest perpendicular distance from an arbitrary line y=mx+b
    // to the center of the platter. We do this so we can generate a %error calculation on our laser line.
    // Ideally, the line should be perfectly on the center, but we acknolodge that this may (probably will) not be
    // the case.

    // endPoints is a vector with intended format of x1,y1,x2,y2 : where x1 and y1 is one endpoint of a line segment
    // and x2, y2 is the other end. ellipseCenter format is meant as a point output of
    // RotatedRectEllipse.center.x , RotatedRectEllipse.center.y : where they are doubles.
    // The function gives a double representing the distance from center to shortest distance to line.

    double m1, m2 ;  // slopes
    double b1, b2 ;  // the B in y=mx+b

    double x1 = endPoints[0] ;
    double y1 = endPoints[1] ;
    double x2 = endPoints[2] ;
    double y2 = endPoints[3] ;

    double length ;

    if ( ((x1-x2)*(y1-y2)) != 0 )   // This traps all lines that are NOT horizontal or vertical
    {
        m1 = (y1-y2)/(x1-x2) ;   // Slope of line segment
        m2 = 1/m1 ;
        b1 = (y1 - (m1*x1)) ;    // calculate B for equation 1
        b2 = (y2 - (m2*x2)) ;    // calculate B for equation 2

        double intersectingX = (b2-b1)/(m1-m2) ;
        double intersectingY = intersectingX*m2 + b2 ;

        length = sqrt( pow(intersectingX-ellipseCenter[0],2) + pow(intersectingY-ellipseCenter[1],2)) ;
        return (length);
    }

    else
    {
        length = ((x1-x2) + (y1-y2)) ;// By definition, one/both of these is 0. The other distance is the distance. Done.
        return (length) ;
    }

}



cv::Point2d calibratewindow::ellipseCenterCorrection(cv::RotatedRect rectangle)
{
    // When I first wrote the algo to detect ellipses (or circular platters in oblique angles), I thought it would be as
    // simple to put a rotated rectangle around the ellipse, and then extract the center from it via rotatedrect.
    // However, I noticed the real centr of the plate APPEARS further above the calculated center. Uhoh...
    // So I decided to find out how much. Turns out, its directly related to the angle of the picture in relation to % error
    // I modelled this with 10 datapoints, and found it's a line.
    // Y = -.3660266639 X + 30.00097135     Where X = asin(short_side/long_side) and Y = % difference where the center is
    // N = 10 , R = -.9959282185, rss = 5.620873341   Or in other words, a really good fit.


    cv::Point2d real_center;
    double x, y ;
    double angle = fmod(rectangle.angle, 180) ;
    qDebug() << angle ;

    if (rectangle.size.width > rectangle.size.height)  //width is 'real' length
    {
        // The longer side is considered the correct length. The shortened side is considered reduced due to angle effect
        x = asin(rectangle.size.height/rectangle.size.width);
        y = (-.3660266639*x + 30.00097135)/100;
        real_center = cv::Point2d( (rectangle.center.x ) , (rectangle.center.y - (rectangle.size.height)*y ) );
    }
    else
    {
        x = asin(rectangle.size.width/rectangle.size.height);
        y = (-.3660266639*x + 30.00097135)/100;
        real_center = cv::Point2d( (rectangle.center.x ) , (rectangle.center.y - (rectangle.size.width)*y ) );
    }



    return(real_center) ;
}




void calibratewindow::on_calibButton1_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    //int board_dt = (settings.value("Calibration/Square_size")).toInt();
    int board_dt = (settings.value("Calibration/frameDelay")).toInt(); // For every frame used as sample, skip this many
    int board_w = (settings.value("Calibration/X")).toInt(); // Board width in squares
    int board_h = (settings.value("Calibration/Y")).toInt(); // Board height
    int n_boards = (settings.value("Calibration/numOfFrames")).toInt(); // Number of pictures for calibration
    int board_n = board_w * board_h;
    QString a = (settings.value("Video/vDevice1" , -1)).toString();
    int vidDevice1 = a.right(1).toInt();

    CvSize board_sz = cvSize( board_w, board_h );
    CvCapture* capture = cvCreateCameraCapture( vidDevice1 );

    int x1 = settings.value("Video/vXAxis1").toInt();
    int y1 = settings.value("Video/vYAxis1").toInt();

    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x1 );
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y1 );

    assert( capture );

    cvNamedWindow( "Calibration" );
    // Allocate Sotrage
    CvMat* image_points         = cvCreateMat( n_boards*board_n, 2, CV_32FC1 );
    CvMat* object_points		= cvCreateMat( n_boards*board_n, 3, CV_32FC1 );
    CvMat* point_counts			= cvCreateMat( n_boards, 1, CV_32SC1 );
    CvMat* intrinsic_matrix		= cvCreateMat( 3, 3, CV_32FC1 );
    CvMat* distortion_coeffs	= cvCreateMat( 5, 1, CV_32FC1 );
    CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
    int corner_count;
    int successes = 0;
    int step, frame = 0;

//    IplImage *image = cvQueryFrame( capture );
//    IplImage *gray_image = cvCreateImage( cvGetSize( image ), 8, 1 );

//    // Capture Corner views loop until we've got n_boards
//    // succesful captures (all corners on the board are found)

//    while( successes < n_boards ){
//        // Skp every board_dt frames to allow user to move chessboard
//        if( frame++ % board_dt == 0 ){
//            // Find chessboard corners:
//            int found = cvFindChessboardCorners( image, board_sz, corners,
//                                                 &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );

//            // Get subpixel accuracy on those corners
//            cvCvtColor( image, gray_image, CV_BGR2GRAY );
//            cvFindCornerSubPix( gray_image, corners, corner_count, cvSize( 11, 11 ),
//                                cvSize( -1, -1 ), cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

//            // Draw it
//            cvDrawChessboardCorners( image, board_sz, corners, corner_count, found );
//            cvShowImage( "Calibration", image );

//            // If we got a good board, add it to our data
//            if( corner_count == board_n ){
//                step = successes*board_n;
//                for( int i=step, j=0; j < board_n; ++i, ++j ){
//                    CV_MAT_ELEM( *image_points, float, i, 0 ) = corners[j].x;
//                    CV_MAT_ELEM( *image_points, float, i, 1 ) = corners[j].y;
//                    CV_MAT_ELEM( *object_points, float, i, 0 ) = j/board_w;
//                    CV_MAT_ELEM( *object_points, float, i, 1 ) = j%board_w;
//                    CV_MAT_ELEM( *object_points, float, i, 2 ) = 0.0f;
//                }
//                CV_MAT_ELEM( *point_counts, int, successes, 0 ) = board_n;
//                successes++;
//            }
//        }

//        // Handle pause/unpause and ESC
//        int c = cvWaitKey( 15 );
//        if( c == 'p' ){
//            c = 0;
//            while( c != 'p' && c != 27 ){
//                c = cvWaitKey( 250 );
//            }
//        }
//        if( c == 27 )
//            return;
//        image = cvQueryFrame( capture ); // Get next image
//    } // End collection while loop

//    // Allocate matrices according to how many chessboards found
//    CvMat* object_points2 = cvCreateMat( successes*board_n, 3, CV_32FC1 );
//    CvMat* image_points2 = cvCreateMat( successes*board_n, 2, CV_32FC1 );
//    CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );

//    // Transfer the points into the correct size matrices
//    for( int i = 0; i < successes*board_n; ++i ){
//        CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0 );
//        CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1 );
//        CV_MAT_ELEM( *object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0 );
//        CV_MAT_ELEM( *object_points2, float, i, 1) = CV_MAT_ELEM( *object_points, float, i, 1 );
//        CV_MAT_ELEM( *object_points2, float, i, 2) = CV_MAT_ELEM( *object_points, float, i, 2 );
//    }

//    for( int i=0; i < successes; ++i ){
//        CV_MAT_ELEM( *point_counts2, int, i, 0 ) = CV_MAT_ELEM( *point_counts, int, i, 0 );
//    }
//    cvReleaseMat( &object_points );
//    cvReleaseMat( &image_points );
//    cvReleaseMat( &point_counts );

//    // At this point we have all the chessboard corners we need
//    // Initiliazie the intrinsic matrix such that the two focal lengths
//    // have a ratio of 1.0

//    CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0;
//    CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0;

//    // Calibrate the camera
//    cvCalibrateCamera2( object_points2, image_points2, point_counts2, cvGetSize( image ),
//                        intrinsic_matrix, distortion_coeffs, NULL, NULL, CV_CALIB_FIX_ASPECT_RATIO );

//    // Save the intrinsics and distortions

    QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics1.xml";
    QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion1.xml";
    QByteArray iname = iFile.toLocal8Bit();
    QByteArray dname = dFile.toLocal8Bit();
    const char *intrinsicName = iname.data();
    const char *distortionName = dname.data();

//    cvSave( intrinsicName, intrinsic_matrix );
//    cvSave( distortionName, distortion_coeffs );
    cvDestroyWindow( "Calibration" );





    QMessageBox msgBox;
    msgBox.setText("Lens Calibration done. Please remove checkerboard from scan.");
    msgBox.exec();


    cv::Mat intrinsic ;
    cv::Mat distortion ;

    qDebug() << intrinsicName << distortionName ;

    cv::FileStorage fsIntrinsic(intrinsicName, cv::FileStorage::READ);
    fsIntrinsic["Intrinsics1"] >> intrinsic;
    cv::FileStorage fsDistortion(distortionName, cv::FileStorage::READ);
    fsDistortion["Distortion1"] >> distortion;
    fsIntrinsic.release();
    fsDistortion.release();


    cv::Mat mapx ;
    cv::Mat mapy ;


    cv::Mat threshold_output, src_gray;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    int thresh = 100;
    cv::namedWindow( "Ellipse and Line Detection", CV_WINDOW_AUTOSIZE );
    cv::Mat dst, canny_dst ;
    int canny_thresh_min = 0;
    int canny_thresh_max = 400;


    do{
        cv::Mat unmap_src = cvQueryFrame( capture );
        cv::Mat src = unmap_src.clone() ;
        cv::undistort(unmap_src, src, intrinsic, distortion);

        cv::blur(src, dst, cv::Size(3,3));
        cv::Canny(dst, canny_dst, canny_thresh_min, canny_thresh_max, 3);
        std::vector<cv::Vec4i> lines;
        cv::HoughLinesP(canny_dst, lines, 1, CV_PI/180, 50, 50, 10 );

        cv::cvtColor(src, src_gray, CV_BGR2GRAY);  // Copy source into a gray_source
        cv::threshold( src_gray, threshold_output, thresh, 255, cv::THRESH_BINARY ); // Detect edges using Threshold
        cv::findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, cv::Point(0, 0) );
        std::vector<cv::RotatedRect> minRect( contours.size() );

        cv::Mat src_clone = src ;
        cv::Scalar red_color = cv::Scalar(0,0,127,127);
        cv::Scalar green_color = cv::Scalar(0,255,0,127);
        double ellipse_x ;
        double ellipse_y ;
        for( int i = 0; i < contours.size(); i++ )
        {
            minRect[i] = minAreaRect( cv::Mat(contours[i]) );
            if( contours[i].size() > 5 )
            {
                cv::drawContours( src_clone, contours, i, cv::Scalar(255,0,0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point() );
                std::vector<cv::RotatedRect> minEllipse( contours.size() );
                double area_of_contours = cv::contourArea(contours[i]);
                cv::RotatedRect rectsize = fitEllipse( cv::Mat(contours[i]) );
                double area_of_ellipse = 3.14159265359 * (rectsize.size.area() ) / 4;
                double percent_error = fabs((area_of_ellipse - area_of_contours)/area_of_contours) * 100 ;
                if (percent_error <  0.2 && area_of_ellipse > 1000){
                    minEllipse[i] = fitEllipse( cv::Mat(contours[i]) );
                    cv::ellipse( src_clone, minEllipse[i], red_color ,-1, 8 );
                    cv::Point2d correctedCenter = ellipseCenterCorrection(rectsize);  // Correction from center of ellipse to real center - read fcn
                    line( src, cv::Point(correctedCenter.x, correctedCenter.y), cv::Point(correctedCenter.x, correctedCenter.y-3), cv::Scalar(255,255,0), 3, CV_AA);
                    for( size_t i = 0; i < lines.size(); i++ )
                            {
                                cv::Vec4i l = lines[i];
                                if( l[0] < rectsize.center.x+rectsize.size.height/2 && l[0] > rectsize.center.x-rectsize.size.height/2 ){
                                    if( l[1] < rectsize.center.y+rectsize.size.width/2 && l[1] > rectsize.center.y-rectsize.size.width/2 ){
                                        if( l[2] < rectsize.center.x+rectsize.size.height/2 && l[2] > rectsize.center.x-rectsize.size.height/2 ){
                                            if( l[3] < rectsize.center.y+rectsize.size.width/2 && l[3] > rectsize.center.y-rectsize.size.width/2 ){
                                                if (shortestDistance(l, cv::Point2d(correctedCenter.x, correctedCenter.y)) < 20)
                                                {
                                                    line( src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), green_color, 3, CV_AA);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                    qDebug() << "%error" << percent_error << rectsize.center.x << rectsize.center.y << correctedCenter.x << correctedCenter.y ;

                    ellipse_x = correctedCenter.x;
                    ellipse_y = correctedCenter.y;
                }
            }
        }
        settings.beginGroup("Calibration");
        settings.setValue("ellipseX1", ellipse_x);
        settings.setValue("ellipseY1", ellipse_y);
        settings.endGroup();

        cv::createTrackbar( "Circle threshhold:", "Ellipse and Line Detection", &thresh, 255 );
        imshow( "Ellipse and Line Detection", src_clone );
    }while(cv::waitKey(30)<0);
    cv::destroyWindow("Ellipse and Line Detection");

    cvReleaseCapture(&capture);
    return;
}








void calibratewindow::on_calibButton2_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    //int board_dt = (settings.value("Calibration/Square_size")).toInt();
    int board_dt = (settings.value("Calibration/frameDelay")).toInt(); // For every frame used as sample, skip this many
    int board_w = (settings.value("Calibration/X")).toInt(); // Board width in squares
    int board_h = (settings.value("Calibration/Y")).toInt(); // Board height
    int n_boards = (settings.value("Calibration/numOfFrames")).toInt(); // Number of pictures for calibration
    int board_n = board_w * board_h;
    QString a = (settings.value("Video/vDevice2" , -1)).toString();
    int vidDevice2 = a.right(1).toInt();

    CvSize board_sz = cvSize( board_w, board_h );
    CvCapture* capture = cvCreateCameraCapture( vidDevice2 );

    int x2 = settings.value("Video/vXAxis2").toInt();
    int y2 = settings.value("Video/vYAxis2").toInt();

    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x2 );
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y2 );

    assert( capture );

    cvNamedWindow( "Calibration" );
    // Allocate Sotrage
    CvMat* image_points         = cvCreateMat( n_boards*board_n, 2, CV_32FC1 );
    CvMat* object_points		= cvCreateMat( n_boards*board_n, 3, CV_32FC1 );
    CvMat* point_counts			= cvCreateMat( n_boards, 1, CV_32SC1 );
    CvMat* intrinsic_matrix		= cvCreateMat( 3, 3, CV_32FC1 );
    CvMat* distortion_coeffs	= cvCreateMat( 5, 1, CV_32FC1 );
    CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
    int corner_count;
    int successes = 0;
    int step, frame = 0;

    IplImage *image = cvQueryFrame( capture );
    IplImage *gray_image = cvCreateImage( cvGetSize( image ), 8, 1 );

    // Capture Corner views loop until we've got n_boards
    // succesful captures (all corners on the board are found)

    while( successes < n_boards ){
        // Skp every board_dt frames to allow user to move chessboard
        if( frame++ % board_dt == 0 ){
            // Find chessboard corners:
            int found = cvFindChessboardCorners( image, board_sz, corners,
                                                 &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );

            // Get subpixel accuracy on those corners
            cvCvtColor( image, gray_image, CV_BGR2GRAY );
            cvFindCornerSubPix( gray_image, corners, corner_count, cvSize( 11, 11 ),
                                cvSize( -1, -1 ), cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

            // Draw it
            cvDrawChessboardCorners( image, board_sz, corners, corner_count, found );
            cvShowImage( "Calibration", image );

            // If we got a good board, add it to our data
            if( corner_count == board_n ){
                step = successes*board_n;
                for( int i=step, j=0; j < board_n; ++i, ++j ){
                    CV_MAT_ELEM( *image_points, float, i, 0 ) = corners[j].x;
                    CV_MAT_ELEM( *image_points, float, i, 1 ) = corners[j].y;
                    CV_MAT_ELEM( *object_points, float, i, 0 ) = j/board_w;
                    CV_MAT_ELEM( *object_points, float, i, 1 ) = j%board_w;
                    CV_MAT_ELEM( *object_points, float, i, 2 ) = 0.0f;
                }
                CV_MAT_ELEM( *point_counts, int, successes, 0 ) = board_n;
                successes++;
            }
        }

        // Handle pause/unpause and ESC
        int c = cvWaitKey( 15 );
        if( c == 'p' ){
            c = 0;
            while( c != 'p' && c != 27 ){
                c = cvWaitKey( 250 );
            }
        }
        if( c == 27 )
            return;
        image = cvQueryFrame( capture ); // Get next image
    } // End collection while loop

    // Allocate matrices according to how many chessboards found
    CvMat* object_points2 = cvCreateMat( successes*board_n, 3, CV_32FC1 );
    CvMat* image_points2 = cvCreateMat( successes*board_n, 2, CV_32FC1 );
    CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );

    // Transfer the points into the correct size matrices
    for( int i = 0; i < successes*board_n; ++i ){
        CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0 );
        CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0 );
        CV_MAT_ELEM( *object_points2, float, i, 1) = CV_MAT_ELEM( *object_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 2) = CV_MAT_ELEM( *object_points, float, i, 2 );
    }

    for( int i=0; i < successes; ++i ){
        CV_MAT_ELEM( *point_counts2, int, i, 0 ) = CV_MAT_ELEM( *point_counts, int, i, 0 );
    }
    cvReleaseMat( &object_points );
    cvReleaseMat( &image_points );
    cvReleaseMat( &point_counts );

    // At this point we have all the chessboard corners we need
    // Initiliazie the intrinsic matrix such that the two focal lengths
    // have a ratio of 1.0

    CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0;
    CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0;

    // Calibrate the camera
    cvCalibrateCamera2( object_points2, image_points2, point_counts2, cvGetSize( image ),
                        intrinsic_matrix, distortion_coeffs, NULL, NULL, CV_CALIB_FIX_ASPECT_RATIO );

    // Save the intrinsics and distortions

    QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics2.xml";
    QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion2.xml";
    QByteArray iname = iFile.toLocal8Bit();
    QByteArray dname = dFile.toLocal8Bit();
    const char *intrinsicName = iname.data();
    const char *distortionName = dname.data();

    cvSave( intrinsicName, intrinsic_matrix );
    cvSave( distortionName, distortion_coeffs );
    cvDestroyWindow( "Calibration" );





    QMessageBox msgBox;
    msgBox.setText("Lens Calibration done. Please remove checkerboard from scan.");
    msgBox.exec();


    cv::Mat intrinsic ;
    cv::Mat distortion ;

    qDebug() << intrinsicName << distortionName ;

    cv::FileStorage fsIntrinsic(intrinsicName, cv::FileStorage::READ);
    fsIntrinsic["Intrinsics2"] >> intrinsic;
    cv::FileStorage fsDistortion(distortionName, cv::FileStorage::READ);
    fsDistortion["Distortion2"] >> distortion;
    fsIntrinsic.release();
    fsDistortion.release();


    cv::Mat mapx ;
    cv::Mat mapy ;


    cv::Mat threshold_output, src_gray;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    int thresh = 100;
    cv::namedWindow( "Ellipse and Line Detection", CV_WINDOW_AUTOSIZE );
    cv::Mat dst, canny_dst ;
    int canny_thresh_min = 0;
    int canny_thresh_max = 400;


    do{
        cv::Mat unmap_src = cvQueryFrame( capture );
        cv::Mat src = unmap_src.clone() ;
        cv::undistort(unmap_src, src, intrinsic, distortion);

        cv::blur(src, dst, cv::Size(3,3));
        cv::Canny(dst, canny_dst, canny_thresh_min, canny_thresh_max, 3);
        std::vector<cv::Vec4i> lines;
        cv::HoughLinesP(canny_dst, lines, 1, CV_PI/180, 50, 50, 10 );

        cv::cvtColor(src, src_gray, CV_BGR2GRAY);  // Copy source into a gray_source
        cv::threshold( src_gray, threshold_output, thresh, 255, cv::THRESH_BINARY ); // Detect edges using Threshold
        cv::findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, cv::Point(0, 0) );
        std::vector<cv::RotatedRect> minRect( contours.size() );

        cv::Mat src_clone = src ;
        cv::Scalar red_color = cv::Scalar(0,0,127,127);
        cv::Scalar green_color = cv::Scalar(0,255,0,127);
        double ellipse_x ;
        double ellipse_y ;
        for( int i = 0; i < contours.size(); i++ )
        {
            minRect[i] = minAreaRect( cv::Mat(contours[i]) );
            if( contours[i].size() > 5 )
            {
                cv::drawContours( src_clone, contours, i, cv::Scalar(255,0,0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point() );
                std::vector<cv::RotatedRect> minEllipse( contours.size() );
                double area_of_contours = cv::contourArea(contours[i]);
                cv::RotatedRect rectsize = fitEllipse( cv::Mat(contours[i]) );
                double area_of_ellipse = 3.14159265359 * (rectsize.size.area() ) / 4;
                double percent_error = fabs((area_of_ellipse - area_of_contours)/area_of_contours) * 100 ;
                if (percent_error <  0.2 && area_of_ellipse > 1000){
                    minEllipse[i] = fitEllipse( cv::Mat(contours[i]) );
                    cv::ellipse( src_clone, minEllipse[i], red_color ,-1, 8 );
                    line( src, cv::Point(rectsize.center.x, rectsize.center.y), cv::Point(rectsize.center.x, rectsize.center.y-1), cv::Scalar(255,255,0), 3, CV_AA);
                    for( size_t i = 0; i < lines.size(); i++ )
                            {
                                cv::Vec4i l = lines[i];
                                if( l[0] < rectsize.center.x+rectsize.size.height/2 && l[0] > rectsize.center.x-rectsize.size.height/2 ){
                                    if( l[1] < rectsize.center.y+rectsize.size.width/2 && l[1] > rectsize.center.y-rectsize.size.width/2 ){
                                        if( l[2] < rectsize.center.x+rectsize.size.height/2 && l[2] > rectsize.center.x-rectsize.size.height/2 ){
                                            if( l[3] < rectsize.center.y+rectsize.size.width/2 && l[3] > rectsize.center.y-rectsize.size.width/2 ){
                                                if (shortestDistance(l, cv::Point2d(rectsize.center.x, rectsize.center.y)) < 20)
                                                {
                                                    line( src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), green_color, 3, CV_AA);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                    qDebug() << "%error" << percent_error << rectsize.center.x << rectsize.center.y ;
                    ellipse_x = rectsize.center.x;
                    ellipse_y = rectsize.center.y;
                }
            }
        }
        settings.beginGroup("Calibration");
        settings.setValue("ellipseX2", ellipse_x);
        settings.setValue("ellipseY2", ellipse_y);
        settings.endGroup();

        cv::createTrackbar( "Circle threshhold:", "Ellipse and Line Detection", &thresh, 255 );
        imshow( "Ellipse and Line Detection", src_clone );
    }while(cv::waitKey(30)<0);
    cv::destroyWindow("Ellipse and Line Detection");

    cvReleaseCapture(&capture);
    return;
}







void calibratewindow::on_calibButton3_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    //int board_dt = (settings.value("Calibration/Square_size")).toInt();
    int board_dt = (settings.value("Calibration/frameDelay")).toInt(); // For every frame used as sample, skip this many
    int board_w = (settings.value("Calibration/X")).toInt(); // Board width in squares
    int board_h = (settings.value("Calibration/Y")).toInt(); // Board height
    int n_boards = (settings.value("Calibration/numOfFrames")).toInt(); // Number of pictures for calibration
    int board_n = board_w * board_h;
    QString a = (settings.value("Video/vDevice3" , -1)).toString();
    int vidDevice3 = a.right(1).toInt();

    CvSize board_sz = cvSize( board_w, board_h );
    CvCapture* capture = cvCreateCameraCapture( vidDevice3 );

    int x3 = settings.value("Video/vXAxis3").toInt();
    int y3 = settings.value("Video/vYAxis3").toInt();

    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x3 );
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y3 );

    assert( capture );

    cvNamedWindow( "Calibration" );
    // Allocate Sotrage
    CvMat* image_points         = cvCreateMat( n_boards*board_n, 2, CV_32FC1 );
    CvMat* object_points		= cvCreateMat( n_boards*board_n, 3, CV_32FC1 );
    CvMat* point_counts			= cvCreateMat( n_boards, 1, CV_32SC1 );
    CvMat* intrinsic_matrix		= cvCreateMat( 3, 3, CV_32FC1 );
    CvMat* distortion_coeffs	= cvCreateMat( 5, 1, CV_32FC1 );
    CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
    int corner_count;
    int successes = 0;
    int step, frame = 0;

    IplImage *image = cvQueryFrame( capture );
    IplImage *gray_image = cvCreateImage( cvGetSize( image ), 8, 1 );

    // Capture Corner views loop until we've got n_boards
    // succesful captures (all corners on the board are found)

    while( successes < n_boards ){
        // Skp every board_dt frames to allow user to move chessboard
        if( frame++ % board_dt == 0 ){
            // Find chessboard corners:
            int found = cvFindChessboardCorners( image, board_sz, corners,
                                                 &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );

            // Get subpixel accuracy on those corners
            cvCvtColor( image, gray_image, CV_BGR2GRAY );
            cvFindCornerSubPix( gray_image, corners, corner_count, cvSize( 11, 11 ),
                                cvSize( -1, -1 ), cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

            // Draw it
            cvDrawChessboardCorners( image, board_sz, corners, corner_count, found );
            cvShowImage( "Calibration", image );

            // If we got a good board, add it to our data
            if( corner_count == board_n ){
                step = successes*board_n;
                for( int i=step, j=0; j < board_n; ++i, ++j ){
                    CV_MAT_ELEM( *image_points, float, i, 0 ) = corners[j].x;
                    CV_MAT_ELEM( *image_points, float, i, 1 ) = corners[j].y;
                    CV_MAT_ELEM( *object_points, float, i, 0 ) = j/board_w;
                    CV_MAT_ELEM( *object_points, float, i, 1 ) = j%board_w;
                    CV_MAT_ELEM( *object_points, float, i, 2 ) = 0.0f;
                }
                CV_MAT_ELEM( *point_counts, int, successes, 0 ) = board_n;
                successes++;
            }
        }

        // Handle pause/unpause and ESC
        int c = cvWaitKey( 15 );
        if( c == 'p' ){
            c = 0;
            while( c != 'p' && c != 27 ){
                c = cvWaitKey( 250 );
            }
        }
        if( c == 27 )
            return;
        image = cvQueryFrame( capture ); // Get next image
    } // End collection while loop

    // Allocate matrices according to how many chessboards found
    CvMat* object_points2 = cvCreateMat( successes*board_n, 3, CV_32FC1 );
    CvMat* image_points2 = cvCreateMat( successes*board_n, 2, CV_32FC1 );
    CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );

    // Transfer the points into the correct size matrices
    for( int i = 0; i < successes*board_n; ++i ){
        CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0 );
        CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0 );
        CV_MAT_ELEM( *object_points2, float, i, 1) = CV_MAT_ELEM( *object_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 2) = CV_MAT_ELEM( *object_points, float, i, 2 );
    }

    for( int i=0; i < successes; ++i ){
        CV_MAT_ELEM( *point_counts2, int, i, 0 ) = CV_MAT_ELEM( *point_counts, int, i, 0 );
    }
    cvReleaseMat( &object_points );
    cvReleaseMat( &image_points );
    cvReleaseMat( &point_counts );

    // At this point we have all the chessboard corners we need
    // Initiliazie the intrinsic matrix such that the two focal lengths
    // have a ratio of 1.0

    CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0;
    CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0;

    // Calibrate the camera
    cvCalibrateCamera2( object_points2, image_points2, point_counts2, cvGetSize( image ),
                        intrinsic_matrix, distortion_coeffs, NULL, NULL, CV_CALIB_FIX_ASPECT_RATIO );

    // Save the intrinsics and distortions

    QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics3.xml";
    QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion3.xml";
    QByteArray iname = iFile.toLocal8Bit();
    QByteArray dname = dFile.toLocal8Bit();
    const char *intrinsicName = iname.data();
    const char *distortionName = dname.data();

    cvSave( intrinsicName, intrinsic_matrix );
    cvSave( distortionName, distortion_coeffs );
    cvDestroyWindow( "Calibration" );





    QMessageBox msgBox;
    msgBox.setText("Lens Calibration done. Please remove checkerboard from scan.");
    msgBox.exec();


    cv::Mat intrinsic ;
    cv::Mat distortion ;

    qDebug() << intrinsicName << distortionName ;

    cv::FileStorage fsIntrinsic(intrinsicName, cv::FileStorage::READ);
    fsIntrinsic["Intrinsics3"] >> intrinsic;
    cv::FileStorage fsDistortion(distortionName, cv::FileStorage::READ);
    fsDistortion["Distortion3"] >> distortion;
    fsIntrinsic.release();
    fsDistortion.release();


    cv::Mat mapx ;
    cv::Mat mapy ;


    cv::Mat threshold_output, src_gray;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    int thresh = 100;
    cv::namedWindow( "Ellipse and Line Detection", CV_WINDOW_AUTOSIZE );
    cv::Mat dst, canny_dst ;
    int canny_thresh_min = 0;
    int canny_thresh_max = 400;


    do{
        cv::Mat unmap_src = cvQueryFrame( capture );
        cv::Mat src = unmap_src.clone() ;
        cv::undistort(unmap_src, src, intrinsic, distortion);

        cv::blur(src, dst, cv::Size(3,3));
        cv::Canny(dst, canny_dst, canny_thresh_min, canny_thresh_max, 3);
        std::vector<cv::Vec4i> lines;
        cv::HoughLinesP(canny_dst, lines, 1, CV_PI/180, 50, 50, 10 );

        cv::cvtColor(src, src_gray, CV_BGR2GRAY);  // Copy source into a gray_source
        cv::threshold( src_gray, threshold_output, thresh, 255, cv::THRESH_BINARY ); // Detect edges using Threshold
        cv::findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, cv::Point(0, 0) );
        std::vector<cv::RotatedRect> minRect( contours.size() );

        cv::Mat src_clone = src ;
        cv::Scalar red_color = cv::Scalar(0,0,127,127);
        cv::Scalar green_color = cv::Scalar(0,255,0,127);
        double ellipse_x ;
        double ellipse_y ;
        for( int i = 0; i < contours.size(); i++ )
        {
            minRect[i] = minAreaRect( cv::Mat(contours[i]) );
            if( contours[i].size() > 5 )
            {
                cv::drawContours( src_clone, contours, i, cv::Scalar(255,0,0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point() );
                std::vector<cv::RotatedRect> minEllipse( contours.size() );
                double area_of_contours = cv::contourArea(contours[i]);
                cv::RotatedRect rectsize = fitEllipse( cv::Mat(contours[i]) );
                double area_of_ellipse = 3.14159265359 * (rectsize.size.area() ) / 4;
                double percent_error = fabs((area_of_ellipse - area_of_contours)/area_of_contours) * 100 ;
                if (percent_error <  0.2 && area_of_ellipse > 1000){
                    minEllipse[i] = fitEllipse( cv::Mat(contours[i]) );
                    cv::ellipse( src_clone, minEllipse[i], red_color ,-1, 8 );
                    line( src, cv::Point(rectsize.center.x, rectsize.center.y), cv::Point(rectsize.center.x, rectsize.center.y-1), cv::Scalar(255,255,0), 3, CV_AA);
                    for( size_t i = 0; i < lines.size(); i++ )
                            {
                                cv::Vec4i l = lines[i];
                                if( l[0] < rectsize.center.x+rectsize.size.height/2 && l[0] > rectsize.center.x-rectsize.size.height/2 ){
                                    if( l[1] < rectsize.center.y+rectsize.size.width/2 && l[1] > rectsize.center.y-rectsize.size.width/2 ){
                                        if( l[2] < rectsize.center.x+rectsize.size.height/2 && l[2] > rectsize.center.x-rectsize.size.height/2 ){
                                            if( l[3] < rectsize.center.y+rectsize.size.width/2 && l[3] > rectsize.center.y-rectsize.size.width/2 ){
                                                if (shortestDistance(l, cv::Point2d(rectsize.center.x, rectsize.center.y)) < 20)
                                                {
                                                    line( src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), green_color, 3, CV_AA);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                    qDebug() << "%error" << percent_error << rectsize.center.x << rectsize.center.y ;
                    ellipse_x = rectsize.center.x;
                    ellipse_y = rectsize.center.y;
                }
            }
        }
        settings.beginGroup("Calibration");
        settings.setValue("ellipseX3", ellipse_x);
        settings.setValue("ellipseY3", ellipse_y);
        settings.endGroup();

        cv::createTrackbar( "Circle threshhold:", "Ellipse and Line Detection", &thresh, 255 );
        imshow( "Ellipse and Line Detection", src_clone );
    }while(cv::waitKey(30)<0);
    cv::destroyWindow("Ellipse and Line Detection");

    cvReleaseCapture(&capture);
    return;

}








void calibratewindow::on_calibButton4_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    //int board_dt = (settings.value("Calibration/Square_size")).toInt();
    int board_dt = (settings.value("Calibration/frameDelay")).toInt(); // For every frame used as sample, skip this many
    int board_w = (settings.value("Calibration/X")).toInt(); // Board width in squares
    int board_h = (settings.value("Calibration/Y")).toInt(); // Board height
    int n_boards = (settings.value("Calibration/numOfFrames")).toInt(); // Number of pictures for calibration
    int board_n = board_w * board_h;
    QString a = (settings.value("Video/vDevice4" , -1)).toString();
    int vidDevice4 = a.right(1).toInt();

    CvSize board_sz = cvSize( board_w, board_h );
    CvCapture* capture = cvCreateCameraCapture( vidDevice4 );

    int x4 = settings.value("Video/vXAxis4").toInt();
    int y4 = settings.value("Video/vYAxis4").toInt();

    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x4 );
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y4 );

    assert( capture );

    cvNamedWindow( "Calibration" );
    // Allocate Sotrage
    CvMat* image_points         = cvCreateMat( n_boards*board_n, 2, CV_32FC1 );
    CvMat* object_points		= cvCreateMat( n_boards*board_n, 3, CV_32FC1 );
    CvMat* point_counts			= cvCreateMat( n_boards, 1, CV_32SC1 );
    CvMat* intrinsic_matrix		= cvCreateMat( 3, 3, CV_32FC1 );
    CvMat* distortion_coeffs	= cvCreateMat( 5, 1, CV_32FC1 );
    CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
    int corner_count;
    int successes = 0;
    int step, frame = 0;

    IplImage *image = cvQueryFrame( capture );
    IplImage *gray_image = cvCreateImage( cvGetSize( image ), 8, 1 );

    // Capture Corner views loop until we've got n_boards
    // succesful captures (all corners on the board are found)

    while( successes < n_boards ){
        // Skp every board_dt frames to allow user to move chessboard
        if( frame++ % board_dt == 0 ){
            // Find chessboard corners:
            int found = cvFindChessboardCorners( image, board_sz, corners,
                                                 &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );

            // Get subpixel accuracy on those corners
            cvCvtColor( image, gray_image, CV_BGR2GRAY );
            cvFindCornerSubPix( gray_image, corners, corner_count, cvSize( 11, 11 ),
                                cvSize( -1, -1 ), cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

            // Draw it
            cvDrawChessboardCorners( image, board_sz, corners, corner_count, found );
            cvShowImage( "Calibration", image );

            // If we got a good board, add it to our data
            if( corner_count == board_n ){
                step = successes*board_n;
                for( int i=step, j=0; j < board_n; ++i, ++j ){
                    CV_MAT_ELEM( *image_points, float, i, 0 ) = corners[j].x;
                    CV_MAT_ELEM( *image_points, float, i, 1 ) = corners[j].y;
                    CV_MAT_ELEM( *object_points, float, i, 0 ) = j/board_w;
                    CV_MAT_ELEM( *object_points, float, i, 1 ) = j%board_w;
                    CV_MAT_ELEM( *object_points, float, i, 2 ) = 0.0f;
                }
                CV_MAT_ELEM( *point_counts, int, successes, 0 ) = board_n;
                successes++;
            }
        }

        // Handle pause/unpause and ESC
        int c = cvWaitKey( 15 );
        if( c == 'p' ){
            c = 0;
            while( c != 'p' && c != 27 ){
                c = cvWaitKey( 250 );
            }
        }
        if( c == 27 )
            return;
        image = cvQueryFrame( capture ); // Get next image
    } // End collection while loop

    // Allocate matrices according to how many chessboards found
    CvMat* object_points2 = cvCreateMat( successes*board_n, 3, CV_32FC1 );
    CvMat* image_points2 = cvCreateMat( successes*board_n, 2, CV_32FC1 );
    CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );

    // Transfer the points into the correct size matrices
    for( int i = 0; i < successes*board_n; ++i ){
        CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0 );
        CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0 );
        CV_MAT_ELEM( *object_points2, float, i, 1) = CV_MAT_ELEM( *object_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 2) = CV_MAT_ELEM( *object_points, float, i, 2 );
    }

    for( int i=0; i < successes; ++i ){
        CV_MAT_ELEM( *point_counts2, int, i, 0 ) = CV_MAT_ELEM( *point_counts, int, i, 0 );
    }
    cvReleaseMat( &object_points );
    cvReleaseMat( &image_points );
    cvReleaseMat( &point_counts );

    // At this point we have all the chessboard corners we need
    // Initiliazie the intrinsic matrix such that the two focal lengths
    // have a ratio of 1.0

    CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0;
    CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0;

    // Calibrate the camera
    cvCalibrateCamera2( object_points2, image_points2, point_counts2, cvGetSize( image ),
                        intrinsic_matrix, distortion_coeffs, NULL, NULL, CV_CALIB_FIX_ASPECT_RATIO );

    // Save the intrinsics and distortions

    QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics4.xml";
    QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion4.xml";
    QByteArray iname = iFile.toLocal8Bit();
    QByteArray dname = dFile.toLocal8Bit();
    const char *intrinsicName = iname.data();
    const char *distortionName = dname.data();

    cvSave( intrinsicName, intrinsic_matrix );
    cvSave( distortionName, distortion_coeffs );
    cvDestroyWindow( "Calibration" );





    QMessageBox msgBox;
    msgBox.setText("Lens Calibration done. Please remove checkerboard from scan.");
    msgBox.exec();


    cv::Mat intrinsic ;
    cv::Mat distortion ;

    qDebug() << intrinsicName << distortionName ;

    cv::FileStorage fsIntrinsic(intrinsicName, cv::FileStorage::READ);
    fsIntrinsic["Intrinsics4"] >> intrinsic;
    cv::FileStorage fsDistortion(distortionName, cv::FileStorage::READ);
    fsDistortion["Distortion4"] >> distortion;
    fsIntrinsic.release();
    fsDistortion.release();


    cv::Mat mapx ;
    cv::Mat mapy ;


    cv::Mat threshold_output, src_gray;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    int thresh = 100;
    cv::namedWindow( "Ellipse and Line Detection", CV_WINDOW_AUTOSIZE );
    cv::Mat dst, canny_dst ;
    int canny_thresh_min = 0;
    int canny_thresh_max = 400;


    do{
        cv::Mat unmap_src = cvQueryFrame( capture );
        cv::Mat src = unmap_src.clone() ;
        cv::undistort(unmap_src, src, intrinsic, distortion);

        cv::blur(src, dst, cv::Size(3,3));
        cv::Canny(dst, canny_dst, canny_thresh_min, canny_thresh_max, 3);
        std::vector<cv::Vec4i> lines;
        cv::HoughLinesP(canny_dst, lines, 1, CV_PI/180, 50, 50, 10 );

        cv::cvtColor(src, src_gray, CV_BGR2GRAY);  // Copy source into a gray_source
        cv::threshold( src_gray, threshold_output, thresh, 255, cv::THRESH_BINARY ); // Detect edges using Threshold
        cv::findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, cv::Point(0, 0) );
        std::vector<cv::RotatedRect> minRect( contours.size() );

        cv::Mat src_clone = src ;
        cv::Scalar red_color = cv::Scalar(0,0,127,127);
        cv::Scalar green_color = cv::Scalar(0,255,0,127);
        double ellipse_x ;
        double ellipse_y ;
        for( int i = 0; i < contours.size(); i++ )
        {
            minRect[i] = minAreaRect( cv::Mat(contours[i]) );
            if( contours[i].size() > 5 )
            {
                cv::drawContours( src_clone, contours, i, cv::Scalar(255,0,0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point() );
                std::vector<cv::RotatedRect> minEllipse( contours.size() );
                double area_of_contours = cv::contourArea(contours[i]);
                cv::RotatedRect rectsize = fitEllipse( cv::Mat(contours[i]) );
                double area_of_ellipse = 3.14159265359 * (rectsize.size.area() ) / 4;
                double percent_error = fabs((area_of_ellipse - area_of_contours)/area_of_contours) * 100 ;
                if (percent_error <  0.2 && area_of_ellipse > 1000){
                    minEllipse[i] = fitEllipse( cv::Mat(contours[i]) );
                    cv::ellipse( src_clone, minEllipse[i], red_color ,-1, 8 );
                    line( src, cv::Point(rectsize.center.x, rectsize.center.y), cv::Point(rectsize.center.x, rectsize.center.y-1), cv::Scalar(255,255,0), 3, CV_AA);
                    for( size_t i = 0; i < lines.size(); i++ )
                            {
                                cv::Vec4i l = lines[i];
                                if( l[0] < rectsize.center.x+rectsize.size.height/2 && l[0] > rectsize.center.x-rectsize.size.height/2 ){
                                    if( l[1] < rectsize.center.y+rectsize.size.width/2 && l[1] > rectsize.center.y-rectsize.size.width/2 ){
                                        if( l[2] < rectsize.center.x+rectsize.size.height/2 && l[2] > rectsize.center.x-rectsize.size.height/2 ){
                                            if( l[3] < rectsize.center.y+rectsize.size.width/2 && l[3] > rectsize.center.y-rectsize.size.width/2 ){
                                                if (shortestDistance(l, cv::Point2d(rectsize.center.x, rectsize.center.y)) < 20)
                                                {
                                                    line( src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), green_color, 3, CV_AA);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                    qDebug() << "%error" << percent_error << rectsize.center.x << rectsize.center.y ;
                    ellipse_x = rectsize.center.x;
                    ellipse_y = rectsize.center.y;
                }
            }
        }
        settings.beginGroup("Calibration");
        settings.setValue("ellipseX4", ellipse_x);
        settings.setValue("ellipseY4", ellipse_y);
        settings.endGroup();

        cv::createTrackbar( "Circle threshhold:", "Ellipse and Line Detection", &thresh, 255 );
        imshow( "Ellipse and Line Detection", src_clone );
    }while(cv::waitKey(30)<0);
    cv::destroyWindow("Ellipse and Line Detection");

    cvReleaseCapture(&capture);
    return;

}



void calibratewindow::on_calibButton5_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    //int board_dt = (settings.value("Calibration/Square_size")).toInt();
    int board_dt = (settings.value("Calibration/frameDelay")).toInt(); // For every frame used as sample, skip this many
    int board_w = (settings.value("Calibration/X")).toInt(); // Board width in squares
    int board_h = (settings.value("Calibration/Y")).toInt(); // Board height
    int n_boards = (settings.value("Calibration/numOfFrames")).toInt(); // Number of pictures for calibration
    int board_n = board_w * board_h;

    QString videoStreamAddress = settings.value("Video/vURL").toString();
    CvSize board_sz = cvSize( board_w, board_h );
    CvCapture* capture = cvCaptureFromFile( videoStreamAddress.toStdString().c_str() );
    cv::waitKey(30);

    int x5 = settings.value("Video/vXAxis5").toInt();
    int y5 = settings.value("Video/vYAxis5").toInt();

    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x5 );
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y5 );

    assert( capture );

    cvNamedWindow( "Calibration" );
    // Allocate Sotrage
    CvMat* image_points         = cvCreateMat( n_boards*board_n, 2, CV_32FC1 );
    CvMat* object_points		= cvCreateMat( n_boards*board_n, 3, CV_32FC1 );
    CvMat* point_counts			= cvCreateMat( n_boards, 1, CV_32SC1 );
    CvMat* intrinsic_matrix		= cvCreateMat( 3, 3, CV_32FC1 );
    CvMat* distortion_coeffs	= cvCreateMat( 5, 1, CV_32FC1 );
    CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
    int corner_count;
    int successes = 0;
    int step, frame = 0;

    IplImage *image = cvQueryFrame( capture );
    IplImage *gray_image = cvCreateImage( cvGetSize( image ), 8, 1 );

    // Capture Corner views loop until we've got n_boards
    // succesful captures (all corners on the board are found)

    while( successes < n_boards ){
        // Skp every board_dt frames to allow user to move chessboard
        if( frame++ % board_dt == 0 ){
            // Find chessboard corners:
            int found = cvFindChessboardCorners( image, board_sz, corners,
                                                 &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );

            // Get subpixel accuracy on those corners
            cvCvtColor( image, gray_image, CV_BGR2GRAY );
            cvFindCornerSubPix( gray_image, corners, corner_count, cvSize( 11, 11 ),
                                cvSize( -1, -1 ), cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

            // Draw it
            cvDrawChessboardCorners( image, board_sz, corners, corner_count, found );
            cvShowImage( "Calibration", image );

            // If we got a good board, add it to our data
            if( corner_count == board_n ){
                step = successes*board_n;
                for( int i=step, j=0; j < board_n; ++i, ++j ){
                    CV_MAT_ELEM( *image_points, float, i, 0 ) = corners[j].x;
                    CV_MAT_ELEM( *image_points, float, i, 1 ) = corners[j].y;
                    CV_MAT_ELEM( *object_points, float, i, 0 ) = j/board_w;
                    CV_MAT_ELEM( *object_points, float, i, 1 ) = j%board_w;
                    CV_MAT_ELEM( *object_points, float, i, 2 ) = 0.0f;
                }
                CV_MAT_ELEM( *point_counts, int, successes, 0 ) = board_n;
                successes++;
            }
        }

        // Handle pause/unpause and ESC
        int c = cvWaitKey( 15 );
        if( c == 'p' ){
            c = 0;
            while( c != 'p' && c != 27 ){
                c = cvWaitKey( 250 );
            }
        }
        if( c == 27 )
            return;
        image = cvQueryFrame( capture ); // Get next image
    } // End collection while loop

    // Allocate matrices according to how many chessboards found
    CvMat* object_points2 = cvCreateMat( successes*board_n, 3, CV_32FC1 );
    CvMat* image_points2 = cvCreateMat( successes*board_n, 2, CV_32FC1 );
    CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );

    // Transfer the points into the correct size matrices
    for( int i = 0; i < successes*board_n; ++i ){
        CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0 );
        CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 0) = CV_MAT_ELEM( *object_points, float, i, 0 );
        CV_MAT_ELEM( *object_points2, float, i, 1) = CV_MAT_ELEM( *object_points, float, i, 1 );
        CV_MAT_ELEM( *object_points2, float, i, 2) = CV_MAT_ELEM( *object_points, float, i, 2 );
    }

    for( int i=0; i < successes; ++i ){
        CV_MAT_ELEM( *point_counts2, int, i, 0 ) = CV_MAT_ELEM( *point_counts, int, i, 0 );
    }
    cvReleaseMat( &object_points );
    cvReleaseMat( &image_points );
    cvReleaseMat( &point_counts );

    // At this point we have all the chessboard corners we need
    // Initiliazie the intrinsic matrix such that the two focal lengths
    // have a ratio of 1.0

    CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0;
    CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0;

    // Calibrate the camera
    cvCalibrateCamera2( object_points2, image_points2, point_counts2, cvGetSize( image ),
                        intrinsic_matrix, distortion_coeffs, NULL, NULL, CV_CALIB_FIX_ASPECT_RATIO );

    // Save the intrinsics and distortions

    QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics5.xml";
    QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion5.xml";
    QByteArray iname = iFile.toLocal8Bit();
    QByteArray dname = dFile.toLocal8Bit();
    const char *intrinsicName = iname.data();
    const char *distortionName = dname.data();

    cvSave( intrinsicName, intrinsic_matrix );
    cvSave( distortionName, distortion_coeffs );
    cvDestroyWindow( "Calibration" );





    QMessageBox msgBox;
    msgBox.setText("Lens Calibration done. Please remove checkerboard from scan.");
    msgBox.exec();


    cv::Mat intrinsic ;
    cv::Mat distortion ;

    qDebug() << intrinsicName << distortionName ;

    cv::FileStorage fsIntrinsic(intrinsicName, cv::FileStorage::READ);
    fsIntrinsic["Intrinsics5"] >> intrinsic;
    cv::FileStorage fsDistortion(distortionName, cv::FileStorage::READ);
    fsDistortion["Distortion5"] >> distortion;
    fsIntrinsic.release();
    fsDistortion.release();


    cv::Mat mapx ;
    cv::Mat mapy ;


    cv::Mat threshold_output, src_gray;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    int thresh = 100;
    cv::namedWindow( "Ellipse and Line Detection", CV_WINDOW_AUTOSIZE );
    cv::Mat dst, canny_dst ;
    int canny_thresh_min = 0;
    int canny_thresh_max = 400;


    do{
        cv::Mat unmap_src = cvQueryFrame( capture );
        cv::Mat src = unmap_src.clone() ;
        cv::undistort(unmap_src, src, intrinsic, distortion);

        cv::blur(src, dst, cv::Size(3,3));
        cv::Canny(dst, canny_dst, canny_thresh_min, canny_thresh_max, 3);
        std::vector<cv::Vec4i> lines;
        cv::HoughLinesP(canny_dst, lines, 1, CV_PI/180, 50, 50, 10 );

        cv::cvtColor(src, src_gray, CV_BGR2GRAY);  // Copy source into a gray_source
        cv::threshold( src_gray, threshold_output, thresh, 255, cv::THRESH_BINARY ); // Detect edges using Threshold
        cv::findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, cv::Point(0, 0) );
        std::vector<cv::RotatedRect> minRect( contours.size() );

        cv::Mat src_clone = src ;
        cv::Scalar red_color = cv::Scalar(0,0,127,127);
        cv::Scalar green_color = cv::Scalar(0,255,0,127);
        double ellipse_x ;
        double ellipse_y ;
        for( int i = 0; i < contours.size(); i++ )
        {
            minRect[i] = minAreaRect( cv::Mat(contours[i]) );
            if( contours[i].size() > 5 )
            {
                cv::drawContours( src_clone, contours, i, cv::Scalar(255,0,0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point() );
                std::vector<cv::RotatedRect> minEllipse( contours.size() );
                double area_of_contours = cv::contourArea(contours[i]);
                cv::RotatedRect rectsize = fitEllipse( cv::Mat(contours[i]) );
                double area_of_ellipse = 3.14159265359 * (rectsize.size.area() ) / 4;
                double percent_error = fabs((area_of_ellipse - area_of_contours)/area_of_contours) * 100 ;
                if (percent_error <  0.2 && area_of_ellipse > 1000){
                    minEllipse[i] = fitEllipse( cv::Mat(contours[i]) );
                    cv::ellipse( src_clone, minEllipse[i], red_color ,-1, 8 );
                    line( src, cv::Point(rectsize.center.x, rectsize.center.y), cv::Point(rectsize.center.x, rectsize.center.y-1), cv::Scalar(255,255,0), 3, CV_AA);
                    for( size_t i = 0; i < lines.size(); i++ )
                            {
                                cv::Vec4i l = lines[i];
                                if( l[0] < rectsize.center.x+rectsize.size.height/2 && l[0] > rectsize.center.x-rectsize.size.height/2 ){
                                    if( l[1] < rectsize.center.y+rectsize.size.width/2 && l[1] > rectsize.center.y-rectsize.size.width/2 ){
                                        if( l[2] < rectsize.center.x+rectsize.size.height/2 && l[2] > rectsize.center.x-rectsize.size.height/2 ){
                                            if( l[3] < rectsize.center.y+rectsize.size.width/2 && l[3] > rectsize.center.y-rectsize.size.width/2 ){
                                                if (shortestDistance(l, cv::Point2d(rectsize.center.x, rectsize.center.y)) < 20)
                                                {
                                                    line( src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), green_color, 3, CV_AA);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                    qDebug() << "%error" << percent_error << rectsize.center.x << rectsize.center.y ;
                    ellipse_x = rectsize.center.x;
                    ellipse_y = rectsize.center.y;
                }
            }
        }
        settings.beginGroup("Calibration");
        settings.setValue("ellipseX5", ellipse_x);
        settings.setValue("ellipseY5", ellipse_y);
        settings.endGroup();

        cv::createTrackbar( "Circle threshhold:", "Ellipse and Line Detection", &thresh, 255 );
        imshow( "Ellipse and Line Detection", src_clone );
    }while(cv::waitKey(30)<0);
    cv::destroyWindow("Ellipse and Line Detection");

    cvReleaseCapture(&capture);
    return;
}
