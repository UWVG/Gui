#include "statuspanel.h"
#include "ui_statuspanel.h"
#include <QDebug>

StatusPanel::StatusPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatusPanel)
{
    ui->setupUi(this);
    qDebug()<<"StatusPanel...";
}

StatusPanel::~StatusPanel()
{
    delete ui;
}

