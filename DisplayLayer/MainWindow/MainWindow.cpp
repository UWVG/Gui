#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlags (Qt::CustomizeWindowHint);
    //setWindowFlags (Qt::FramelessWindowHint);
    player = new Player(this);
    connect(player,SIGNAL(signal_widget(QWidget*)),
            this,SLOT(slot_widget(QWidget*)));
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
        ui->verticalLayout->addWidget(widget);
    }
}
void MainWindow::slot_widget1(QWidget* widget)
{
    if(widget)
    {
        this->widget = widget;
        ui->verticalLayout->addWidget(widget);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(player)
    {
        connect(player,SIGNAL(signal_widget(QWidget*)),
                this,SLOT(slot_widget(QWidget*)));
        player->begin();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    //player->deleteLater();
    if(widget)
    {


        player->stop();



//        player->deleteLater();
    }
    //connect(widget,SIGNAL(destroyed()),this,SLOT(player_delete_later(player)));

}

void MainWindow::player_delete_later(Player* player)
{
    qDebug()<<"player_delete_later";
    player->deleteLater();
}
