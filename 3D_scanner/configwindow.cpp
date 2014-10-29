#include "configwindow.h"
#include "ui_configwindow.h"
#include "mainwindow.h"
#include <QProcess>
#include <QFileDialog>
#include <QDesktopServices>
#include <QLineEdit>
#include <QDebug>

configwindow::configwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configwindow)
{
    ui->setupUi(this);

    QSettings settings("JoshCrawleySoft", "3D_Scanner");

    ui->vXAxis1->setPlaceholderText( (settings.value("Video/vXAxis1").toString() ) );
    ui->vYAxis1->setPlaceholderText( (settings.value("Video/vYAxis1").toString() ) );
    ui->centerX1->setPlaceholderText( (settings.value("Calibration/ellipseX1").toString() ));
    ui->centerY1->setPlaceholderText( (settings.value("Calibration/ellipseY1").toString() ));
    QString a1 = (settings.value("Video/vDevice1" , "-1")).toString();
    int vidDevice1 = a1.right(1).toInt();
    if (a1.length() != 0) {
        ui->vDevice1->setCurrentIndex(vidDevice1 + 1);
    }

    ui->vXAxis2->setPlaceholderText( (settings.value("Video/vXAxis2").toString() ) );
    ui->vYAxis2->setPlaceholderText( (settings.value("Video/vYAxis2").toString() ) );
    ui->centerX2->setPlaceholderText( (settings.value("Calibration/ellipseX2").toString() ));
    ui->centerY2->setPlaceholderText( (settings.value("Calibration/ellipseY2").toString() ));
    QString a2 = (settings.value("Video/vDevice2" , "-1")).toString();
    int vidDevice2 = a2.right(1).toInt();
    if (a2.length() != 0) {
        ui->vDevice2->setCurrentIndex(vidDevice2 + 1);
    }


    ui->vXAxis3->setPlaceholderText( (settings.value("Video/vXAxis3").toString() ) );
    ui->vYAxis3->setPlaceholderText( (settings.value("Video/vYAxis3").toString() ) );
    ui->centerX3->setPlaceholderText( (settings.value("Calibration/ellipseX3").toString() ));
    ui->centerY3->setPlaceholderText( (settings.value("Calibration/ellipseY3").toString() ));
    QString a3 = (settings.value("Video/vDevice3" , "-1")).toString();
    int vidDevice3 = a3.right(1).toInt();
    if (a3.length() != 0) {
        ui->vDevice3->setCurrentIndex(vidDevice3 + 1);
    }


    ui->vXAxis4->setPlaceholderText( (settings.value("Video/vXAxis4").toString() ) );
    ui->vYAxis4->setPlaceholderText( (settings.value("Video/vYAxis4").toString() ) );
    ui->centerX4->setPlaceholderText( (settings.value("Calibration/ellipseX4").toString() ));
    ui->centerY4->setPlaceholderText( (settings.value("Calibration/ellipseY4").toString() ));
    QString a4 = (settings.value("Video/vDevice4" , "-1")).toString();
    int vidDevice4 = a4.right(1).toInt();
    if (a4.length() != 0) {
        ui->vDevice4->setCurrentIndex(vidDevice4 + 1);
    }

    ui->vURL->setPlaceholderText( (settings.value("Video/vURL").toString() ) );
    ui->vXAxis5->setPlaceholderText( (settings.value("Video/vXAxis5").toString() ) );
    ui->vYAxis5->setPlaceholderText( (settings.value("Video/vYAxis5").toString() ) );
    ui->centerX5->setPlaceholderText( (settings.value("Calibration/ellipseX5").toString() ));
    ui->centerY5->setPlaceholderText( (settings.value("Calibration/ellipseY5").toString() ));


    ui->fileSaveLocation->setPlaceholderText( settings.value("Calibration/fileStorage").toString() );
    ui->width->setPlaceholderText( (settings.value("Calibration/X")).toString() );
    ui->height->setPlaceholderText( (settings.value("Calibration/Y")).toString() );
    ui->sqSize->setPlaceholderText( settings.value("Calibration/Square_size").toString() );
    ui->numOfFrames->setPlaceholderText( (settings.value("Calibration/numOfFrames")).toString() );
    ui->frameDelay->setPlaceholderText((settings.value("Calibration/frameDelay")).toString() );

}

configwindow::~configwindow()
{
    delete ui;
}


//Video device selecters -------------------------

void configwindow::on_vDevice1_currentIndexChanged(QString index)
{
    configwindow::SaveSettings( "Video", "vDevice1", index );
};

void configwindow::on_vDevice2_currentIndexChanged(QString index)
{
    configwindow::SaveSettings( "Video", "vDevice2", index );
};

void configwindow::on_vDevice3_currentIndexChanged(QString index)
{
    configwindow::SaveSettings( "Video", "vDevice3", index );
};

void configwindow::on_vDevice4_currentIndexChanged(QString index)
{
    configwindow::SaveSettings( "Video", "vDevice4", index );
};

//Video resolution selecters -------------------------

void configwindow::on_vResolution1_currentIndexChanged(QString index)
{
    if (ui->radioButton->isChecked() == true)
    {
        int j=0;
        if((j = index.indexOf("x", j))  < 0 ){
            ++j;
        }
        QString index_x = index.left(j);
        QString index_y = index.right(j);
        configwindow::SaveSettings( "Video", "vXAxis1", index_x );
        configwindow::SaveSettings( "Video", "vYAxis1", index_y );
    };
};

void configwindow::on_vResolution2_currentIndexChanged(QString index)
{
    if (ui->radioButton_3->isChecked() == true)
        {
            int j=0;
            if((j = index.indexOf("x", j))  < 0 ){
                ++j;
            }
            QString index_x = index.left(j);
            QString index_y = index.right(j);
            configwindow::SaveSettings( "Video", "vXAxis2", index_x );
            configwindow::SaveSettings( "Video", "vYAxis2", index_y );
        };
};

void configwindow::on_vResolution3_currentIndexChanged(QString index)
{
    if (ui->radioButton_5->isChecked() == true)
        {
            int j=0;
            if((j = index.indexOf("x", j))  < 0 ){
                ++j;
            }
            QString index_x = index.left(j);
            QString index_y = index.right(j);
            configwindow::SaveSettings( "Video", "vXAxis3", index_x );
            configwindow::SaveSettings( "Video", "vYAxis3", index_y );
        };
};

void configwindow::on_vResolution4_currentIndexChanged(QString index)
{
    if (ui->radioButton_13->isChecked() == true)
    {
        int j=0;
        if((j = index.indexOf("x", j))  < 0 ){
            ++j;
        }
        QString index_x = index.left(j);
        QString index_y = index.right(j);
        configwindow::SaveSettings( "Video", "vXAxis4", index_x );
        configwindow::SaveSettings( "Video", "vYAxis4", index_y );
    };
};

void configwindow::on_vResolution5_currentIndexChanged(QString index)
{
    if (ui->radioButton_15->isChecked() == true)
    {
        int j=0;
        if((j = index.indexOf("x", j))  < 0 ){
            ++j;
        }
        QString index_x = index.left(j);
        QString index_y = index.right(j);
        configwindow::SaveSettings( "Video", "vXAxis5", index_x );
        configwindow::SaveSettings( "Video", "vYAxis5", index_y );
    };
}




void configwindow::SaveSettings(QString value, QString key, QString varible)
{
QSettings settings("JoshCrawleySoft", "3D_Scanner");
settings.beginGroup(value);
settings.setValue(key, varible);
settings.endGroup();
}





void configwindow::on_vXAxis1_returnPressed()
{
    if (ui->radioButton_2->isChecked() == true)
        {
        QString x = ui->vXAxis1->text();
        configwindow::SaveSettings( "Video", "vXAxis1", x );
        }
}

void configwindow::on_vYAxis1_returnPressed()
{
    if (ui->radioButton_2->isChecked() == true)
        {
        QString y = ui->vYAxis1->text();
        configwindow::SaveSettings( "Video", "vYAxis1", y );
        }
}

void configwindow::on_vXAxis2_returnPressed()
{
    if (ui->radioButton_4->isChecked() == true)
        {
        QString x = ui->vXAxis2->text();
        configwindow::SaveSettings( "Video", "vXAxis2", x );
        }
}

void configwindow::on_vYAxis2_returnPressed()
{
    if (ui->radioButton_4->isChecked() == true)
        {
        QString y = ui->vYAxis2->text();
        configwindow::SaveSettings( "Video", "vYAxis2", y );
        }
}

void configwindow::on_vXAxis3_returnPressed()
{
    if (ui->radioButton_6->isChecked() == true)
        {
        QString x = ui->vXAxis3->text();
        configwindow::SaveSettings( "Video", "vXAxis3", x );
        }
}

void configwindow::on_vYAxis3_returnPressed()
{
    if (ui->radioButton_6->isChecked() == true)
        {
        QString y = ui->vYAxis3->text();
        configwindow::SaveSettings( "Video", "vYAxis3", y );
        }
}

void configwindow::on_vXAxis4_returnPressed()
{
    if (ui->radioButton_14->isChecked() == true)
        {
        QString x = ui->vXAxis4->text();
        configwindow::SaveSettings( "Video", "vXAxis4", x );
        }
}

void configwindow::on_vYAxis4_returnPressed()
{
    if (ui->radioButton_14->isChecked() == true)
        {
        QString y = ui->vYAxis4->text();
        configwindow::SaveSettings( "Video", "vYAxis4", y );
        }
}

void configwindow::on_vXAxis5_returnPressed()
{
    if (ui->radioButton_16->isChecked() == true)
        {
        QString x = ui->vXAxis5->text();
        configwindow::SaveSettings( "Video", "vXAxis5", x );
        }
}

void configwindow::on_vYAxis5_returnPressed()
{
    if (ui->radioButton_16->isChecked() == true)
        {
        QString y = ui->vYAxis5->text();
        configwindow::SaveSettings( "Video", "vYAxis5", y );
        }
}

void configwindow::on_vURL_returnPressed()
{
    QString url = ui->vURL->text();
    configwindow::SaveSettings( "Video", "vURL", url );
}

void configwindow::on_width_editingFinished()
{
    QString x = ui->width->text();
    configwindow::SaveSettings( "Calibration", "X", x );
}

void configwindow::on_height_editingFinished()
{
    QString y = ui->height->text();
    configwindow::SaveSettings( "Calibration", "Y", y );
}

void configwindow::on_sqSize_editingFinished()
{
    QString square = ui->sqSize->text();
    configwindow::SaveSettings( "Calibration", "Square_size", square );
}

void configwindow::on_numOfFrames_editingFinished()
{
    QString frameNum = ui->numOfFrames->text();
    configwindow::SaveSettings( "Calibration", "numOfFrames", frameNum );
}

void configwindow::on_frameDelay_editingFinished()
{
    QString frameMS = ui->frameDelay->text();
    configwindow::SaveSettings( "Calibration", "frameDelay", frameMS );
}

void configwindow::on_FileSave_clicked()
{
    QString directoryName = QFileDialog::getExistingDirectory(this, tr("Save Location"),
                                        "/home",
                                        QFileDialog::ShowDirsOnly
                                        | QFileDialog::DontResolveSymlinks);
    ui->fileSaveLocation->setText(directoryName);
    configwindow::SaveSettings( "Calibration", "fileStorage", directoryName );

}


void configwindow::on_centerX1_editingFinished()
{
    QString ellipse_center_x = ui->centerX1->text();
    configwindow::SaveSettings( "Calibration", "ellipseX1", ellipse_center_x );
}

void configwindow::on_centerY1_editingFinished()
{
    QString ellipse_center_y = ui->centerY1->text();
    configwindow::SaveSettings( "Calibration", "ellipseY1", ellipse_center_y );
}

void configwindow::on_centerX2_editingFinished()
{
    QString ellipse_center_x = ui->centerX2->text();
    configwindow::SaveSettings( "Calibration", "ellipseX2", ellipse_center_x );
}

void configwindow::on_centerY2_editingFinished()
{
    QString ellipse_center_y = ui->centerY2->text();
    configwindow::SaveSettings( "Calibration", "ellipseY2", ellipse_center_y );
}

void configwindow::on_centerX3_editingFinished()
{
    QString ellipse_center_x = ui->centerX3->text();
    configwindow::SaveSettings( "Calibration", "ellipseX3", ellipse_center_x );
}

void configwindow::on_centerY3_editingFinished()
{
    QString ellipse_center_y = ui->centerY3->text();
    configwindow::SaveSettings( "Calibration", "ellipseY3", ellipse_center_y );
}

void configwindow::on_centerX4_editingFinished()
{
    QString ellipse_center_x = ui->centerX4->text();
    configwindow::SaveSettings( "Calibration", "ellipseX4", ellipse_center_x );
}

void configwindow::on_centerY4_editingFinished()
{
    QString ellipse_center_y = ui->centerY4->text();
    configwindow::SaveSettings( "Calibration", "ellipseY4", ellipse_center_y );
}

void configwindow::on_centerX5_editingFinished()
{
    QString ellipse_center_x = ui->centerX5->text();
    configwindow::SaveSettings( "Calibration", "ellipseX5", ellipse_center_x );
}

void configwindow::on_centerY5_editingFinished()
{
    QString ellipse_center_y = ui->centerY5->text();
    configwindow::SaveSettings( "Calibration", "ellipseY5", ellipse_center_y );
}
