/**********************************************************************
**File name:gamepadwidget.cpp
**Author:hexiao<hexiao.hrbeu.edu.cn>    Version:1.0    Date:2020.12.21
**Description:
** Function List:
**
**GPL-3.0 License Usage
**********************************************************************/

#include "gamepadwidget.h"
#include <QDebug>

GamePadWidget::GamePadWidget(QWidget *parent) : QWidget(parent)
{
    qmlRegisterType<GamePadIFS>("an.qt.GamePadIFS",1,0,"GamePadIFS");
    quickWidget = new QQuickWidget(this);
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    QUrl source("qrc:/main.qml");
    quickWidget->setSource(source);
    gamePadIFS = GamePadIFS::getInstance();
    connect(gamePadIFS,SIGNAL(update(int,double)),
            this,SLOT(update(int,double)));
}

GamePadWidget::~GamePadWidget()
{
    quickWidget->deleteLater();
}
void GamePadWidget::update(int x,double y)
{
    qDebug()<<"x="<<x<<"y="<<y<<"\n";
    switch(x)
    {
    case GamePadIFS::ButtonA:
        break;
    case GamePadIFS::AxisLeftX:
        emit servo_ctl((y*100+100)/1);
    default:
        break;
    }
}
