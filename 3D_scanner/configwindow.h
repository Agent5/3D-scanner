#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include <QtCore>
#include <QDebug>
#include <QSettings>

namespace Ui {
class configwindow;
}

class configwindow : public QDialog
{
    Q_OBJECT

public:
    explicit configwindow(QWidget *parent = 0);
    ~configwindow();

private slots:
    void on_vDevice1_currentIndexChanged(QString index);

    void on_vDevice2_currentIndexChanged(QString index);

    void on_vDevice3_currentIndexChanged(QString index);

    void on_vDevice4_currentIndexChanged(QString index);

    void on_vResolution1_currentIndexChanged(QString index);

    void on_vResolution2_currentIndexChanged(QString index);

    void on_vResolution3_currentIndexChanged(QString index);

    void on_vResolution4_currentIndexChanged(QString index);

    void on_vXAxis1_returnPressed();

    void on_vYAxis1_returnPressed();

    void on_vXAxis2_returnPressed();

    void on_vYAxis2_returnPressed();

    void on_vXAxis3_returnPressed();

    void on_vYAxis3_returnPressed();

    void on_vXAxis4_returnPressed();

    void on_vYAxis4_returnPressed();

    void on_vResolution5_currentIndexChanged(QString index);

    void on_vXAxis5_returnPressed();

    void on_vYAxis5_returnPressed();

    void on_vURL_returnPressed();

    void on_width_editingFinished();

    void on_height_editingFinished();

    void on_sqSize_editingFinished();

    void on_numOfFrames_editingFinished();

    void on_frameDelay_editingFinished();

    void on_FileSave_clicked();


    void on_centerX1_editingFinished();

    void on_centerY1_editingFinished();

    void on_centerX2_editingFinished();

    void on_centerY2_editingFinished();

    void on_centerX3_editingFinished();

    void on_centerY3_editingFinished();

    void on_centerX4_editingFinished();

    void on_centerY4_editingFinished();

    void on_centerX5_editingFinished();

    void on_centerY5_editingFinished();

private:
    Ui::configwindow *ui;
//    void LoadSettings(void);
    void SaveSettings(QString, QString, QString);
};

#endif // CONFIGWINDOW_H
