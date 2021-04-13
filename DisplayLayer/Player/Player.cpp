#include "Player.h"
#include <Windows.h>
#include <QDebug>
#include <QWindow>
#include <QWidget>

#pragma comment(lib,"user32")

Player::Player(QObject *parent) : QThread(parent)
{
    isBusy = false;
    connect(this,SIGNAL(signal_handle(quint64,bool)),
            this,SLOT(slot_handle(quint64,bool)));
    playerProc = new QProcess(this);
}
Player::~Player()
{
    qDebug()<<"进入Player的析构函数！";

}

void Player::begin()
{
    if(!isBusy)
    {

        playerProc->start("ffplay/ffplay.exe", QStringList() << "rtmp://58.200.131.2:1935/livetv/cctv1hd");
        this->start();
        isBusy = true;

    }
}

void Player::stop()
{
    window->setParent(nullptr);
    window->deleteLater();
    widget->setParent(nullptr);
    widget->deleteLater();
    playerProc->kill();
}

void Player::run()
{
    int flag = 0;
    qDebug() << "D:/Gui/He/Gui.exe";
    // Get child process handle
    WId childId = (WId)FindWindow(L"SDL_app", L"rtmp://58.200.131.2:1935/livetv/cctv1hd");

    int n = 0;
    while (true) {
        Sleep(1);
        childId = (WId)FindWindow(L"SDL_app", L"rtmp://58.200.131.2:1935/livetv/cctv1hd");
        if (childId != 0){
            flag = 1;
            break;
        } else if(n++ > 5000) {
            qDebug()<<"failed!!";
        }
    }
    if(flag)
    {
        emit signal_handle(childId,1);
    }
    else
        emit signal_handle(childId,0);

}

void Player::slot_handle(quint64 handle,bool status)
{
    if(status)
    {
        HWND childHwnd = (HWND)handle;
        //SetWindowPos(childHwnd,HWND_TOP,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
        //SetWindowPos(childHwnd,HWND_BOTTOM,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);

        window = QWindow::fromWinId((WId)childHwnd);

        //m_window->setFlags(Qt::WindowShadeButtonHint|Qt::WindowTitleHint);
        //m_window->setGeometry(QRect(0,0,520,420));
        widget = QWidget::createWindowContainer(window);
        widget->setGeometry(QRect(0,0,320,180));
        emit signal_widget(widget);
        isBusy = false;
    }
    else
    {
        emit signal_widget(nullptr);
        isBusy = false;
    }
}
