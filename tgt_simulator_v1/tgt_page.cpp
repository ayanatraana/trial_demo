#include "tgt_page.h"
#include "ui_tgt_page.h"
#include <QDebug>
#include <QIntValidator>

tgt_page::tgt_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tgt_page)
{
    ui->setupUi(this);
    ui->tgt_typ_comboBox->addItem("Cattle");
    ui->tgt_typ_comboBox->addItem("Man");
    ui->tgt_typ_comboBox->addItem("Vehicle");

    ui->rad_movt_comboBox->addItem("Incoming");
    ui->rad_movt_comboBox->addItem("Outgoing");

    /*----Make sure the values taken are only integers-----*/
    QValidator * val = new QIntValidator(this);
    ui->radial_dist_lineEdit->setValidator(val);
    ui->az_lineEdit->setValidator(val);
    ui->speed_lineEdit->setValidator(val);
    ui->time_lineEdit->setValidator(val);
    ui->time_offset_lineEdit->setValidator(val);
    ui->time_offset_lineEdit->setText("0");
}

tgt_page::~tgt_page()
{
    delete ui;
}


void tgt_page::on_save_pushButton_pressed()
{
    QString tgt_typ = ui->tgt_typ_comboBox->currentText();
    QString tgt_typ1 = ui->comboBox->currentText();
    QString rad_dist = ui->radial_dist_lineEdit->text();
    QString az = ui->az_lineEdit->text();
    QString speed = ui->speed_lineEdit->text();
    QString rad_movt = ui->rad_movt_comboBox->currentText();
    QString time = ui->time_lineEdit->text();
    QString tim_offset = ui->time_offset_lineEdit->text();


    qDebug () << "Type of the target is " << tgt_typ << "+" << tgt_typ1; /* To verify the values provided  provided by the user and the values taken are matching    */
    qDebug () << "Radial distance : " << rad_dist;
    qDebug () << "Azimuth with respect to North :" << az;
    qDebug () << "Speed of the target = " << speed;
    qDebug () << "Radial Movement is " << rad_movt;
    qDebug () << "Time  = " << time;
    qDebug () << "Time Offset from simulator start" << tim_offset;
    if(ui->loop_radioButton->isChecked())
    {
        qDebug() << "To be played in loop";
    }
    else
    {
        qDebug() << "Do not play in loop";
    }

}


void tgt_page::on_tgt_typ_comboBox_currentIndexChanged(int index)
{
    index = ui->tgt_typ_comboBox->currentIndex();
    ui->comboBox->show();
    switch (index) {
    case 0:
        ui->comboBox->hide();
        break;
    case 1:
        ui->comboBox->clear();
        ui->comboBox->addItem("Single");
        ui->comboBox->addItem("Group");
        break;
    case 2:
        ui->comboBox->clear();
        ui->comboBox->addItem("Truck");
        ui->comboBox->addItem("Tank");
        ui->comboBox->addItem("Bicycle");
        ui->comboBox->addItem("Two Wheeler");
        ui->comboBox->addItem("Car");
        ui->comboBox->addItem("Bus");
        break;
    default:
        break;
    }
}


void tgt_page::on_cancel_pushButton_pressed()
{
    ui->tgt_typ_comboBox->clear();
    ui->comboBox->hide();
    ui->radial_dist_lineEdit->clear();
    ui->az_lineEdit->clear();
    ui->speed_lineEdit->clear();
    ui->time_lineEdit->clear();
    ui->time_offset_lineEdit->setText("0");
    ui->loop_radioButton->setChecked(false);

}

