#include "configwindow.h"
#include "ui_configwindow.h"
#include "mainwindow.h"
#include <QProcess>

configwindow::configwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configwindow)
{
    ui->setupUi(this);
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



void configwindow::LoadSettings()
{

};



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
