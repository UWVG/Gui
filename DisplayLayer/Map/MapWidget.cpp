#include "MapWidget.h"
#include <QDebug>
MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{
    webContext = new WebContext(this);
    webChannel = new QWebChannel(this);
    webChannel->registerObject("context",webContext);

    view = new QWebEngineView(this);

    view->load(QUrl("qrc:///html/map.html"));
    view->page()->setWebChannel(webChannel);
    view->resize(500,400);
    view->show();
}
