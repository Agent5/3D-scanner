#include "scanwindow.h"
#include "ui_scanwindow.h"

scanwindow::scanwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scanwindow)
{
    ui->setupUi(this);
}

scanwindow::~scanwindow()
{
    delete ui;
}
