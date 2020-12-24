#ifndef WEBCONTEXT_H
#define WEBCONTEXT_H

#include <QObject>
#include <QJsonObject>
#include <QWebEnginePage>
#include <QJsonArray>

class WebContext : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString content MEMBER m_content)
    //Q_PROPERTY(QString content MEMBER m_content NOTIFY contentChanged)
    Q_PROPERTY(QJsonObject content MEMBER m_content NOTIFY contentChanged)
public:

    explicit WebContext(QObject *parent = nullptr);
    void sendMsg(QWebEnginePage* page, const QString& msg);

signals:
    //void contentChanged(const QString &str);
    void contentChanged(const QJsonObject &str);
signals:
public slots:
    void onMsg(const QJsonArray &msg);
private:
    QJsonObject m_content;
};

#endif // WEBCONTEXT_H
