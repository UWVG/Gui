#ifndef GAMEPADINTERFACE_H
#define GAMEPADINTERFACE_H

#include <QObject>

class GamePadInterFace : public QObject
{
    Q_OBJECT
public:
    explicit GamePadInterFace(QObject *parent = nullptr);

signals:

public slots:
    void valueChanged(int x,double y);

};

#endif // GAMEPADINTERFACE_H
