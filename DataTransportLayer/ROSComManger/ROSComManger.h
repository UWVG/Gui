#ifndef ROSCOMMANGER_H
#define ROSCOMMANGER_H

#include <QObject>

#include "WindowsSocketClient.h"
#include "ros/node_handle.h"
#include "std_msgs/UInt32.h"
#include "std_msgs/Float32.h"

class ROSComManager : public QObject
{
    Q_OBJECT
public:
    explicit ROSComManager(QObject *parent = nullptr);
    int start();
    void loop();
private:
    ros::NodeHandle_<WindowsSocketClient> nodeHandle;
    ros::Publisher *servo_pub;
    std_msgs::UInt32 servo_msg;
    std_msgs::Float32 servo1_msg;
public slots:
    void servo_ctl(uint32_t);
};

#endif // ROSCOMMANGER_H
