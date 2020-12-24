#include "webcontext.h"

WebContext::WebContext(QObject *parent) : QObject(parent)
{

}


void WebContext::sendMsg(QWebEnginePage* page, const QString& msg)
{
    page->runJavaScript(QString("recvMessage('%1');").arg(msg));
}

void WebContext::onMsg(const QJsonArray &msg)
{
    int cmd = msg.at(0).toInt();
    switch(cmd)
    {
        case 1:
            qDebug()<<msg;
            qDebug()<< msg.at(0).toString().toInt();
        break;
    }

}

