#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configwindow.h"
#include "camerawindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_configureButton_clicked()
{
    configwindow config;
    config.setModal(true);
    config.exec();
}

void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_viewCameraButton_clicked()
{
    camerawindow camera;
    camera.setModal(true);
    camera.exec();
}
