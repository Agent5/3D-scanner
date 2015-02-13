#ifndef CALIBRATEWINDOW_H
#define CALIBRATEWINDOW_H
#include "opencv2/opencv.hpp"

#include <QDialog>

namespace Ui {
class calibratewindow;
}

class calibratewindow : public QDialog
{
    Q_OBJECT

public:
    explicit calibratewindow(QWidget *parent = 0);
    ~calibratewindow();
    double shortestDistance(cv::Vec4i endPoints, cv::Vec2d ellipseCenter) ;
    cv::Point2d ellipseCenterCorrection(cv::RotatedRect rectangle);

private slots:
    void on_calibButton1_clicked();

    void on_calibButton2_clicked();

    void on_calibButton3_clicked();

    void on_calibButton4_clicked();

    void on_calibButton5_clicked();

private:
    Ui::calibratewindow *ui;
};

#endif // CALIBRATEWINDOW_H
