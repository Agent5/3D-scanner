#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

#include <QDialog>

namespace Ui {
class camerawindow;
}

class camerawindow : public QDialog
{
    Q_OBJECT

public:
    explicit camerawindow(QWidget *parent = 0);
    ~camerawindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::camerawindow *ui;
};

#endif // CAMERAWINDOW_H
