/**********************************************************************
**File name:gamepadwidget.h
**Author:hexiao<hexiao.hrbeu.edu.cn>    Version:1.0    Date:2020.12.21
**Description:
**GPL-3.0 License Usage
**********************************************************************/

#ifndef GAMEPADWIDGET_H
#define GAMEPADWIDGET_H

#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>
#include "gamepadifs.h"

class GamePadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GamePadWidget(QWidget *parent = nullptr);
    ~GamePadWidget();

private:
    QQuickWidget    *quickWidget;
    GamePadIFS      *gamePadIFS;


public slots:
    void update(int,double);
};

#endif // GAMEPADWIDGET_H
