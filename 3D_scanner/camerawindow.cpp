#include "camerawindow.h"
#include "ui_camerawindow.h"
#include <cv.h>
#include <highgui.h>
#include <QSettings>
#include <QDebug>
#include <QtCore>
#include <QFuture>
#include <QtConcurrent>

camerawindow::camerawindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::camerawindow)
{
    ui->setupUi(this);
}

camerawindow::~camerawindow()
{
    delete ui;
}



void camerawindow::on_pushButton_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    std::string name1 = "Video1";  // We pass this to the thread creator to see what's what
    QString a = (settings.value("Video/vDevice1" , -1)).toString();  //Get variable from file
    int vidDevice1 = a.right(1).toInt();  //Convert QString to integer to feed to VideoCapture
    int x1 = settings.value("Video/vXAxis1").toInt(); //Obvious X is X
    int y1 = settings.value("Video/vYAxis1").toInt(); //Obvious Y is Y
    
    if( ui->calib1->isChecked() == true){

        cvNamedWindow("Calibrated VidWindow 1");
        QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics1.xml";
        QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion1.xml";
        QByteArray iname = iFile.toLocal8Bit();
        QByteArray dname = dFile.toLocal8Bit();
        const char *intrinsicName = iname.data();
        const char *distortionName = dname.data();
        CvMat *intrinsic = (CvMat*)cvLoad( intrinsicName );
        CvMat *distortion = (CvMat*)cvLoad( distortionName ); //Above sets up standard variables for this section

        CvCapture* capture = cvCreateCameraCapture( vidDevice1 );
        assert( capture != NULL );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x1 );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y1 );

        IplImage *frame1 = cvQueryFrame( capture );

        IplImage* mapx = cvCreateImage( cvGetSize( frame1 ), IPL_DEPTH_32F, 1 ); //Calculate transients X
        IplImage* mapy = cvCreateImage( cvGetSize( frame1 ), IPL_DEPTH_32F, 1 ); //Calculate transients Y
        cvInitUndistortMap( intrinsic, distortion, mapx, mapy ); //precomputes calib matrix

        while ( frame1 ) {
            IplImage *temp = cvCloneImage( frame1 );
            cvRemap( temp, frame1, mapx, mapy );
            cvReleaseImage( &temp );
            cvShowImage( "Calibrated VidWindow 1", frame1 );
            int c = cvWaitKey( 15 );
            if( c == 'p' ){
                        c = 0;
                        while( c != 'p' && c != 27 ){
                            c = cvWaitKey( 250 );
                        }
                    }
                    if( c == 27 ){
                        cvDestroyWindow("Calibrated VidWindow 1");
                        cvReleaseCapture(&capture);
                        break;}
            frame1 = cvQueryFrame( capture );

        }
    }
    else {
        cv::namedWindow(name1);
        cv::VideoCapture cap1 = cv::VideoCapture(vidDevice1);
        cap1.set(CV_CAP_PROP_FRAME_WIDTH, x1 );
        cap1.set(CV_CAP_PROP_FRAME_HEIGHT, y1 );
        cv::Mat frame1;
        do{
            cap1 >> frame1;
            imshow(name1 ,frame1);
            //cap1.release();
        }while(cv::waitKey(30)<0);
        cv::destroyWindow(name1);
        }
}


void camerawindow::on_pushButton_2_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    std::string name2 = "Video2";  // We pass this to the thread creator to see what's what
    QString a = (settings.value("Video/vDevice2" , -1)).toString();  //Get variable from file
    int vidDevice2 = a.right(1).toInt();  //Convert QString to integer to feed to VideoCapture
    int x2 = settings.value("Video/vXAxis2").toInt(); //Obvious X is X
    int y2 = settings.value("Video/vYAxis2").toInt(); //Obvious Y is Y

    if( ui->calib2->isChecked() == true){

        cvNamedWindow("Calibrated VidWindow 2");
        QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics2.xml";
        QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion2.xml";
        QByteArray iname = iFile.toLocal8Bit();
        QByteArray dname = dFile.toLocal8Bit();
        const char *intrinsicName = iname.data();
        const char *distortionName = dname.data();
        CvMat *intrinsic = (CvMat*)cvLoad( intrinsicName );
        CvMat *distortion = (CvMat*)cvLoad( distortionName ); //Above sets up standard variables for this section

        CvCapture* capture = cvCreateCameraCapture( vidDevice2 );
        assert( capture != NULL );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x2 );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y2 );

        IplImage *frame2 = cvQueryFrame( capture );

        IplImage* mapx = cvCreateImage( cvGetSize( frame2 ), IPL_DEPTH_32F, 1 ); //Calculate transients X
        IplImage* mapy = cvCreateImage( cvGetSize( frame2 ), IPL_DEPTH_32F, 1 ); //Calculate transients Y
        cvInitUndistortMap( intrinsic, distortion, mapx, mapy ); //precomputes calib matrix

        while ( frame2 ) {
            IplImage *temp = cvCloneImage( frame2 );
            cvRemap( temp, frame2, mapx, mapy );
            cvReleaseImage( &temp );
            cvShowImage( "Calibrated VidWindow 2", frame2 );
            int c = cvWaitKey( 15 );
            if( c == 'p' ){
                        c = 0;
                        while( c != 'p' && c != 27 ){
                            c = cvWaitKey( 250 );
                        }
                    }
                    if( c == 27 ){
                        cvDestroyWindow("Calibrated VidWindow 2");
                        cvReleaseCapture(&capture);
                        break;}
            frame2 = cvQueryFrame( capture );

        }
    }
    else {
        cv::namedWindow(name2);
        cv::VideoCapture cap2 = cv::VideoCapture(vidDevice2);
        cap2.set(CV_CAP_PROP_FRAME_WIDTH, x2 );
        cap2.set(CV_CAP_PROP_FRAME_HEIGHT, y2 );
        cv::Mat frame2;
        do{
            cap2 >> frame2;
            imshow(name2 ,frame2);
            //cap2.release();
        }while(cv::waitKey(30)<0);
        cv::destroyWindow(name2);
    }
}

void camerawindow::on_pushButton_3_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    std::string name3 = "Video3";  // We pass this to the thread creator to see what's what
    QString a = (settings.value("Video/vDevice3" , -1)).toString();  //Get variable from file
    int vidDevice3 = a.right(1).toInt();  //Convert QString to integer to feed to VideoCapture
    int x3 = settings.value("Video/vXAxis3").toInt(); //Obvious X is X
    int y3 = settings.value("Video/vYAxis3").toInt(); //Obvious Y is Y
    if( ui->calib3->isChecked() == true){

        cvNamedWindow("Calibrated VidWindow 3");
        QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics3.xml";
        QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion3.xml";
        QByteArray iname = iFile.toLocal8Bit();
        QByteArray dname = dFile.toLocal8Bit();
        const char *intrinsicName = iname.data();
        const char *distortionName = dname.data();
        CvMat *intrinsic = (CvMat*)cvLoad( intrinsicName );
        CvMat *distortion = (CvMat*)cvLoad( distortionName ); //Above sets up standard variables for this section

        CvCapture* capture = cvCreateCameraCapture( vidDevice3 );
        assert( capture != NULL );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x3 );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y3 );

        IplImage *frame3 = cvQueryFrame( capture );

        IplImage* mapx = cvCreateImage( cvGetSize( frame3 ), IPL_DEPTH_32F, 1 ); //Calculate transients X
        IplImage* mapy = cvCreateImage( cvGetSize( frame3 ), IPL_DEPTH_32F, 1 ); //Calculate transients Y
        cvInitUndistortMap( intrinsic, distortion, mapx, mapy ); //precomputes calib matrix

        while ( frame3 ) {
            IplImage *temp = cvCloneImage( frame3 );
            cvRemap( temp, frame3, mapx, mapy );
            cvReleaseImage( &temp );
            cvShowImage( "Calibrated VidWindow 3", frame3 );
            int c = cvWaitKey( 15 );
            if( c == 'p' ){
                        c = 0;
                        while( c != 'p' && c != 27 ){
                            c = cvWaitKey( 250 );
                        }
                    }
                    if( c == 27 ){
                        cvDestroyWindow("Calibrated VidWindow 3");
                        cvReleaseCapture(&capture);
                        break;}
            frame3 = cvQueryFrame( capture );

        }

        }
    else {
        cv::namedWindow(name3);
        cv::VideoCapture cap3 = cv::VideoCapture(vidDevice3);
        cap3.set(CV_CAP_PROP_FRAME_WIDTH, x3 );
        cap3.set(CV_CAP_PROP_FRAME_HEIGHT, y3 );
        cv::Mat frame3;
        do{
            cap3 >> frame3;
            imshow(name3 ,frame3);
            //cap3.release();
        }while(cv::waitKey(30)<0);
        cv::destroyWindow(name3);
    }
}

void camerawindow::on_pushButton_4_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    std::string name4 = "Video4";  // We pass this to the thread creator to see what's what
    QString a = (settings.value("Video/vDevice4" , -1)).toString();  //Get variable from file
    int vidDevice4 = a.right(1).toInt();  //Convert QString to integer to feed to VideoCapture
    int x4 = settings.value("Video/vXAxis4").toInt(); //Obvious X is X
    int y4 = settings.value("Video/vYAxis4").toInt(); //Obvious Y is Y
    if( ui->calib4->isChecked() == true){

        cvNamedWindow("Calibrated VidWindow 4");
        QString iFile = settings.value("Calibration/fileStorage").toString() + "/Intrinsics4.xml";
        QString dFile = settings.value("Calibration/fileStorage").toString() + "/Distortion4.xml";
        QByteArray iname = iFile.toLocal8Bit();
        QByteArray dname = dFile.toLocal8Bit();
        const char *intrinsicName = iname.data();
        const char *distortionName = dname.data();
        CvMat *intrinsic = (CvMat*)cvLoad( intrinsicName );
        CvMat *distortion = (CvMat*)cvLoad( distortionName ); //Above sets up standard variables for this section

        CvCapture* capture = cvCreateCameraCapture( vidDevice4 );
        assert( capture != NULL );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, x4 );
        cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, y4 );

        IplImage *frame4 = cvQueryFrame( capture );

        IplImage* mapx = cvCreateImage( cvGetSize( frame4 ), IPL_DEPTH_32F, 1 ); //Calculate transients X
        IplImage* mapy = cvCreateImage( cvGetSize( frame4 ), IPL_DEPTH_32F, 1 ); //Calculate transients Y
        cvInitUndistortMap( intrinsic, distortion, mapx, mapy ); //precomputes calib matrix

        while ( frame4 ) {
            IplImage *temp = cvCloneImage( frame4 );
            cvRemap( temp, frame4, mapx, mapy );
            cvReleaseImage( &temp );
            cvShowImage( "Calibrated VidWindow 4", frame4 );
            int c = cvWaitKey( 15 );
            if( c == 'p' ){
                        c = 0;
                        while( c != 'p' && c != 27 ){
                            c = cvWaitKey( 250 );
                        }
                    }
                    if( c == 27 ){
                        cvDestroyWindow("Calibrated VidWindow 4");
                        cvReleaseCapture(&capture);
                        break;}
            frame4 = cvQueryFrame( capture );

        }
        }
    else {
        cv::namedWindow(name4);
        cv::VideoCapture cap4 = cv::VideoCapture(vidDevice4);
        cap4.set(CV_CAP_PROP_FRAME_WIDTH, x4 );
        cap4.set(CV_CAP_PROP_FRAME_HEIGHT, y4 );
        cv::Mat frame4;
        do{
            cap4 >> frame4;
            imshow(name4 ,frame4);
            //cap4.release();
        }while(cv::waitKey(30)<0);
        cv::destroyWindow(name4);
    }
}

void camerawindow::on_pushButton_5_clicked()
{

        QFuture<void> future = QtConcurrent::run(this,&camerawindow::ipcam);
        future.waitForFinished();
}


void camerawindow::ipcam()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    QString videoStreamAddress = settings.value("Video/vURL").toString();
    const std::string vSA = videoStreamAddress.toUtf8().constData();
    cv::VideoCapture cap5 = cv::VideoCapture(vSA);
    cv::Mat frame5;
    cv::namedWindow("Video5");

    do{
        cap5 >> frame5;
        imshow("Video5",frame5);
    }while(cv::waitKey(30)<0);
}


