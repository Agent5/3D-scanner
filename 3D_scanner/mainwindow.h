#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_configureButton_clicked();

    void on_quitButton_clicked();

    void on_viewCameraButton_clicked();

    void on_calibrateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
