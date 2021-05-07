#include "radiosignalstrength.h"

RadioSignalStrength::RadioSignalStrength(QObject * parent) : QThread(parent)
{
    qRegisterMetaType<struct Signal>("Signal");
    isRun = true;
}


void RadioSignalStrength::run()
{
    while(isRun)
    {
        _spider((char *)"192.168.137.25",&signalMaster);
        emit signal_master(signalMaster);
        _spider((char*)"192.168.137.69",&signalSlave);
        emit signal_slave(signalSlave);
    }
}

void RadioSignalStrength::begin()
{
    isRun = true;
    start();
}

void RadioSignalStrength::stop()
{
    isRun = false;
    wait();
}
