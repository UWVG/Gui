#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   qRegisterMetaType<uint32_t>("uint32_t");
    //setWindowFlags (Qt::CustomizeWindowHint);
    //setWindowFlags (Qt::FramelessWindowHint);
    player = new Player(this);
    player1 = new Player(this);
    comThread = new ComThread(this);
    connect(comThread,SIGNAL(sig_connect()),
            this,SLOT(slot_connect()));
    connect(player,SIGNAL(signal_widget(QWidget*)),
            this,SLOT(slot_widget(QWidget*)));
    connect(player1,SIGNAL(signal_widget(QWidget*)),
            this,SLOT(slot_widget1(QWidget*)));
    ui->label->setStyleSheet("border:1px solid red");
    ui->label_2->setStyleSheet("border:1px solid red");
    comThread->start();
}

void MainWindow::slot_connect()
{
    qDebug()<<"Enter slot connect!\n";
    connect(ui->widget,SIGNAL(servo_ctl(uint32_t)),
            comThread->getInstance(),SLOT(servo_ctl(uint32_t)));
}

void MainWindow::slot_a(uint32_t data)
{
    qDebug()<<"slot print:"<<data<<"\n";
}
MainWindow::~MainWindow()
{
    qDebug()<<"进入析构";

    //player->deleteLater();

    delete ui;
}
void MainWindow::slot_widget(QWidget* widget)
{
    if(widget)
    {
        this->widget = widget;
        ui->label->hide();
        ui->verticalLayout->addWidget(widget);
        widget->setFixedSize(400,225);
    }
}
void MainWindow::slot_widget1(QWidget* widget)
{
    if(widget)
    {
        this->widget1 = widget;
        ui->label_2->hide();
        ui->verticalLayout_2->addWidget(widget);
        widget->setFixedSize(400,225);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(player)
    {
        player->begin();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(widget)
    {
        player->stop();
        ui->label->setHidden(0);
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    if(player1)
    {
        player1->begin();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(widget1)
    {
        player1->stop();
        ui->label_2->setHidden(0);
    }
}
void MainWindow::player_delete_later(Player* player)
{
    qDebug()<<"player_delete_later";
    player->deleteLater();
}




