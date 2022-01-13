#include "ROSComManger.h"
#include "time.h"
#include <QDebug>
#include <QThread>
ROSComManager::ROSComManager(QObject *parent) : QObject(parent)
{
    servo_pub = new ros::Publisher("D_pwm",&servo1_msg);
    nodeHandle.advertise(*servo_pub);
}

int ROSComManager::start()
{
        nodeHandle.getHardware()->set_port(11411);
        nodeHandle.getHardware()->set_addr((char*)"192.168.1.3");
        nodeHandle.initNode();
        nodeHandle.spinOnce();
        qDebug()<<"start"<<QThread::currentThread()<<"\n";
        return 0;
}

void ROSComManager::loop()
{
        nodeHandle.spinOnce();
//        qDebug()<<"Loop"<<QThread::currentThread()<<"\n";
}

void ROSComManager::servo_ctl(uint32_t data)
{

    servo1_msg.data = data/200.0*270;
    servo_pub->publish(&servo1_msg);
    qDebug()<<"ctl"<<QThread::currentThread()<<"\n";
}
