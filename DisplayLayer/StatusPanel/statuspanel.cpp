#include "statuspanel.h"
#include "ui_statuspanel.h"
#include <QDebug>

StatusPanel::StatusPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatusPanel)
{
    ui->setupUi(this);
    radioSignalStrength = new RadioSignalStrength(this);
    connect(radioSignalStrength,SIGNAL(signal_master(struct Signal)),\
            this,SLOT(slot_signal_master(struct Signal)));
    connect(radioSignalStrength,SIGNAL(signal_slave(struct Signal)),\
            this,SLOT(slot_signal_slave(struct Signal)));
    radioSignalStrength->begin();
    qDebug()<<"StatusPanel...";
}

StatusPanel::~StatusPanel()
{
    radioSignalStrength->stop();
    delete ui;
}

void StatusPanel::slot_signal_master(struct Signal signal)
{
//    qDebug()<<"MASTER~"<<"Noise:"<<signal.Noise<<"SNR:"<<signal.SNR<<"RSSI"<<signal.RSSI<<"\n";
    ui->lineEdit_MasterNoise->setText(QString::number(signal.Noise));
    ui->lineEdit_MasterSNR->setText(QString::number(signal.SNR));
    ui->lineEdit_MasterRSSI->setText(QString::number(signal.RSSI));
}

void StatusPanel::slot_signal_slave(struct Signal signal)
{
//    qDebug()<<"SLAVE~~"<<"Noise:"<<signal.Noise<<"SNR:"<<signal.SNR<<"RSSI"<<signal.RSSI<<"\n";
    ui->lineEdit_SlaveNoise->setText(QString::number(signal.Noise));
    ui->lineEdit_SlaveSNR->setText(QString::number(signal.SNR));
    ui->lineEdit_SlaveRSSI->setText(QString::number(signal.RSSI));
}
