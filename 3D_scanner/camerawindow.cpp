#include "camerawindow.h"
#include "ui_camerawindow.h"
#include <cv.h>
#include <highgui.h>
#include <QSettings>
#include <QDebug>

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
    int vidDevice1;

    cv::namedWindow("Video1");
    QString a = (settings.value("Video/vDevice1" , -1)).toString();
    if (a.toInt() != -1){
    vidDevice1 = a.right(1).toInt() - 1;
        int x1 = settings.value("Video/vXAxis1").toInt();
        int y1 = settings.value("Video/vYAxis1").toInt();
        cv::VideoCapture cap1 = cv::VideoCapture(int(vidDevice1));
        cap1.set(CV_CAP_PROP_FRAME_WIDTH, x1 );
        cap1.set(CV_CAP_PROP_FRAME_HEIGHT, y1 );
        cv::Mat frame;
        do{
            cap1 >> frame;
            imshow("Video1",frame);
        }while(cv::waitKey(30)<0);
    }
    //imwrite( "/home/josh/openCV_snap.jpg", frame );
    cv::destroyAllWindows();
}

void camerawindow::on_pushButton_2_clicked()
{
    QSettings settings("JoshCrawleySoft", "3D_Scanner");
    int vidDevice2;

    cv::namedWindow("Video2");
    QString a = (settings.value("Video/vDevice2" , -1)).toString();

    if (a.toInt() != -1){
        vidDevice2 = a.right(1).toInt() - 1;
        int x1 = settings.value("Video/vXAxis2").toInt();
        int y1 = settings.value("Video/vYAxis2").toInt();
        cv::VideoCapture cap2 = cv::VideoCapture(int(vidDevice2));
        cap2.set(CV_CAP_PROP_FRAME_WIDTH, x1 );
        cap2.set(CV_CAP_PROP_FRAME_HEIGHT, y1 );
        cv::Mat frame;
        do{
            cap2 >> frame;
            imshow("Video2",frame);
        }while(cv::waitKey(30)<0);
    }

    //imwrite( "/home/josh/openCV_snap.jpg", frame );
    cv::destroyAllWindows();
}

void camerawindow::on_pushButton_3_clicked()
{
    {
        QSettings settings("JoshCrawleySoft", "3D_Scanner");
        int vidDevice3;

        cv::namedWindow("Video3");
        QString a = (settings.value("Video/vDevice3" , -1)).toString();

        if (a.toInt() != -1){
            vidDevice3 = a.right(1).toInt() - 1;
            int x1 = settings.value("Video/vXAxis3").toInt();
            int y1 = settings.value("Video/vYAxis3").toInt();
            cv::VideoCapture cap3 = cv::VideoCapture(int(vidDevice3));
            cap3.set(CV_CAP_PROP_FRAME_WIDTH, x1 );
            cap3.set(CV_CAP_PROP_FRAME_HEIGHT, y1 );
            cv::Mat frame;
            do{
                cap3 >> frame;
                imshow("Video3",frame);
            }while(cv::waitKey(30)<0);
        }

        //imwrite( "/home/josh/openCV_snap.jpg", frame );
        cv::destroyAllWindows();
    }
}

void camerawindow::on_pushButton_4_clicked()
{
    {
        QSettings settings("JoshCrawleySoft", "3D_Scanner");
        int vidDevice4;

        cv::namedWindow("Video4");
        QString a = (settings.value("Video/vDevice4" , -1)).toString();

        if (a.toInt() != -1){
            vidDevice4 = a.right(1).toInt() - 1;
            int x1 = settings.value("Video/vXAxis4").toInt();
            int y1 = settings.value("Video/vYAxis4").toInt();
            cv::VideoCapture cap4 = cv::VideoCapture(int(vidDevice4));
            cap4.set(CV_CAP_PROP_FRAME_WIDTH, x1 );
            cap4.set(CV_CAP_PROP_FRAME_HEIGHT, y1 );
            cv::Mat frame;
            do{
                cap4 >> frame;
                imshow("Video4",frame);
            }while(cv::waitKey(30)<0);
        }

        //imwrite( "/home/josh/openCV_snap.jpg", frame );
        cv::destroyAllWindows();
    }
}

void camerawindow::on_pushButton_5_clicked()
{
        QSettings settings("JoshCrawleySoft", "3D_Scanner");
        QString videoStreamAddress = settings.value("Video/vURL").toString();
        const std::string vSA = videoStreamAddress.toUtf8().constData();
        cv::VideoCapture cap5 = cv::VideoCapture(vSA);
        cv::Mat frame;
        cv::namedWindow("Video5");

        do{
            cap5 >> frame;
            imshow("Video5",frame);
        }while(cv::waitKey(30)<0);
}
