#ifndef PLAYER_H
#define PLAYER_H

#include <QThread>
#include <QObject>
#include <QProcess>
#include <QWindow>



class Player : public QThread
{
    Q_OBJECT
public:
    explicit Player(QObject * parent = nullptr);
    ~Player();
    void run();
    void begin();
    void stop();
    QString     playerPath;
    QProcess    *playerProc;
    bool        isBusy;
    QWindow     *window;
    QWidget     *widget;
signals:
    void signal_handle(quint64,bool);
    void signal_widget(QWidget*);
public slots:
    void slot_handle(quint64,bool);
private:

};

#endif // PLAYER_H
