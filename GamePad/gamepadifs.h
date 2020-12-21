/**********************************************************************
**File name:gamepadifs.h
**Author:hexiao<hexiao.hrbeu.edu.cn>    Version:1.0    Date:2020.12.19
**Description:Get data from main.qml and emit update signal
**GPL-3.0 License Usage
**********************************************************************/

#ifndef GAMEPADINTERFACE_H
#define GAMEPADINTERFACE_H

#include <QObject>

class GamePadIFS : public QObject
{
    Q_OBJECT
    Q_ENUMS(GamePadKey)

public:
    explicit GamePadIFS(QObject *parent = nullptr);
    static GamePadIFS* getInstance()
    {
        return gamePadIFS;
    }

    enum GamePadKey{
        ButtonA,
        ButtonB,
        ButtonX,
        ButtonY,
        AxisLeftX,
        AxisLeftY,
        AxisRightX,
        AxisRightY,
        ButtonUp,
        ButtonDown,
        ButtonLeft,
        ButtonRight,
        ButtonL1,
        ButtonL2,
        ButtonL3,
        ButtonR1,
        ButtonR2,
        ButtonR3
    };

signals:
    void update(int,double);

private:
    static GamePadIFS* gamePadIFS;

public slots:
    void valueChanged(int x,double y);

};

#endif // GAMEPADINTERFACE_H
