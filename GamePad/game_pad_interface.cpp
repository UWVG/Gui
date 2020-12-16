#include "game_pad_interface.h"
#include <QDebug>

GamePadInterFace::GamePadInterFace(QObject *parent) : QObject(parent)
{

}

void GamePadInterFace::valueChanged(int x,double y)
{
    qDebug()<<"x="<<x<<"y="<<y<<"\n";
}
