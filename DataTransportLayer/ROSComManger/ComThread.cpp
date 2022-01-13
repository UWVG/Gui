#include "ComThread.h"
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
ComThread::ComThread(QObject *parent) : QThread(parent)
{
    rosComManager = nullptr;
}

ComThread::~ComThread()
{
    requestInterruption();
    quit();
    wait();
}

ROSComManager* ComThread::getInstance()
{
    return rosComManager;
}

void ComThread::run()
{
    QEventLoop eventloop;

    rosComManager = new ROSComManager();
    rosComManager->start();
    emit sig_connect();
    qDebug()<<"run"<<QThread::currentThread()<<"\n";
    while(!isInterruptionRequested())
    {
        QTimer::singleShot(1, &eventloop, SLOT(quit()));
        rosComManager->loop();
        eventloop.exec();
    }
}

