#include "calibratewindow.h"
#include "ui_calibratewindow.h"
#include <cv.h>
#include <highgui.h>
#include <QSettings>

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

    QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics1.xml";
    QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion1.xml";
    QByteArray iname = iFile.toLocal8Bit();
    QByteArray dname = dFile.toLocal8Bit();
    const char *intrinsicName = iname.data();
    const char *distortionName = dname.data();

    cvSave( intrinsicName, intrinsic_matrix );
    cvSave( distortionName, distortion_coeffs );
    cvDestroyWindow( "Calibration" );
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
    return;

//    // Example of loading these matrices back in
//    CvMat *intrinsic = (CvMat*)cvLoad( intrinsicName );
//    CvMat *distortion = (CvMat*)cvLoad( distortionName );
//
//    // Build the undistort map that we will use for all subsequent frames
//    IplImage* mapx = cvCreateImage( cvGetSize( image ), IPL_DEPTH_32F, 1 );
//    IplImage* mapy = cvCreateImage( cvGetSize( image ), IPL_DEPTH_32F, 1 );
//    cvInitUndistortMap( intrinsic, distortion, mapx, mapy );
//
//    // Run the camera to the screen, now showing the raw and undistorted image
//    cvNamedWindow( "Undistort" );
//
//    while( image ){
//        IplImage *t = cvCloneImage( image );
//        cvRemap( t, image, mapx, mapy ); // undistort image
//        cvReleaseImage( &t );
//        cvShowImage( "Undistort", image ); // Show corrected image
//
//        // Handle pause/unpause and esc
//        int c = cvWaitKey( 15 );
//        if( c == 'p' ){
//            c = 0;
//            while( c != 'p' && c != 27 ){
//                c = cvWaitKey( 250 );
//            }
//        }
//        if( c == 27 )
//            break;
//        image = cvQueryFrame( capture );
//    }
//    return;
}

