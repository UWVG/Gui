#include "gpsdialog.h"
#include "ui_gpsdialog.h"

#include <QDebug>

GPSDialog::GPSDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPSDialog)
{
    ui->setupUi(this);
}

GPSDialog::~GPSDialog()
{
    delete ui;
}

