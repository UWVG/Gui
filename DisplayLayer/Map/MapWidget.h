#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include <QJsonObject>
#include <QWebChannel>
#include "webcontext.h"

class MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = nullptr);
private:
    QWebChannel     *webChannel;
    WebContext      *webContext;
    QWebEngineView  *view;
signals:

};

#endif // MAPWIDGET_H
