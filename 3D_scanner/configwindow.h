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

private:
    Ui::configwindow *ui;
    void LoadSettings();
    void SaveSettings(QString, QString, QString);
};

#endif // CONFIGWINDOW_H
