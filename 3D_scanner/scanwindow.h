#ifndef SCANWINDOW_H
#define SCANWINDOW_H

#include <QDialog>

namespace Ui {
class scanwindow;
}

class scanwindow : public QDialog
{
    Q_OBJECT

public:
    explicit scanwindow(QWidget *parent = 0);
    ~scanwindow();

private:
    Ui::scanwindow *ui;
};

#endif // SCANWINDOW_H
