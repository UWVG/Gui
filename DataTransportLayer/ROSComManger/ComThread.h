#ifndef COMTHREAD_H
#define COMTHREAD_H

#include <QThread>
#include <QObject>
#include <QMutex>
#include "ROSComManger.h"

class ComThread : public QThread
{
    Q_OBJECT
public:
    explicit ComThread(QObject *parent = nullptr);
    ~ComThread();
    ROSComManager* getInstance();
    virtual void run();
signals:
    void sig_connect();
private:
    ROSComManager *rosComManager;
    QMutex mutex;
};

#endif // COMTHREAD_H
