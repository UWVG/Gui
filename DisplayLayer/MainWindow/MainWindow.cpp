#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DisplayLayer/Player/PlayerWidget.h"
#include <QProcess>
#define HDEBUG
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlags (Qt::CustomizeWindowHint);
    //setWindowFlags (Qt::FramelessWindowHint);
#ifdef HDEBUG
    QProcess *playerProcess = new QProcess(this);
    playerProcess->start("D:/Gui/He1/Gui.exe", QStringList() << "http://127.0.0.1:5050");


    qDebug() << "D:/Gui/He/Gui.exe";

    // Get child process handle
    WId childId = (WId)FindWindow(L"Qt5152QWindowIcon", L"MainWindow");
    int n = 0;
    while (true) {
        Sleep(1);
        childId = (WId)FindWindow(L"Qt5152QWindowIcon", L"MainWindow");
        if (childId != 0) {
            break;
        } else if(n++ > 5000) {
            qDebug()<<"failed!!";
        }
    }
    qDebug()<<"sasdfa!!";
    HWND childHwnd = (HWND)childId;
//    SetWindowPos(childHwnd,HWND_TOP,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
//    SetWindowPos(childHwnd,HWND_BOTTOM,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
    QWindow *m_window;
    m_window = QWindow::fromWinId((WId)childHwnd);

    //m_window->setFramePosition(QPoint(-10,200));
    m_window->setFlags(Qt::WindowShadeButtonHint|Qt::WindowTitleHint);
//    m_window->setWidth(500);
//    m_window->setHeight(400);
    qDebug()<<"Widget geometry="<<this->height();
    m_window->setGeometry(QRect(0,0,520,420));

    QWidget *m_widget = QWidget::createWindowContainer(m_window,this,Qt::SubWindow);
    m_widget->setGeometry(QRect(0,0,520,420));
    ui->verticalLayout->addWidget(m_widget);

    //m_widget->setGeometry(QRect(0,0,520,420));
    //this->setCentralWidget(m_widget);
   // m_widget->show();
    //SetParent(childHwnd,(HWND)this->winId());
    //this->focusWidget();
    //m_widget->show();
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}
