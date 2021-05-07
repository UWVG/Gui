#ifndef RADIOSIGNALSTRENGTH_H
#define RADIOSIGNALSTRENGTH_H

#include <QThread>
#include <QObject>
#include "spider.h"

class RadioSignalStrength : public QThread
{
    Q_OBJECT
public:
    RadioSignalStrength(QObject * parent = nullptr);
    void run();
    void begin();
    void stop();
private:
    struct Signal signalMaster;
    struct Signal signalSlave;
    bool   isRun;
signals:
    void signal_master(struct Signal);
    void signal_slave(struct Signal);
};

#endif // RADIOSIGNALSTRENGTH_H
