/**********************************************************************
**File name:gamepadifs.cpp
**Author:hexiao<hexiao.hrbeu.edu.cn>    Version:1.0    Date:2020.12.19
**Description:
** Function List:
**    1.void valueChanged(int,double)
**GPL-3.0 License Usage
**********************************************************************/

#include "gamepadifs.h"

GamePadIFS* GamePadIFS::gamePadIFS = nullptr;

GamePadIFS::GamePadIFS(QObject *parent) : QObject(parent)
{
    gamePadIFS = this;
}

void GamePadIFS::valueChanged(int x,double y)
{
    emit update(x,y);
}
