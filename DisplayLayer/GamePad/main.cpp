#include <QApplication>
#include <QQmlApplicationEngine>
#include <gamepadifs.h>
#include "gamepadwidget.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GamePadWidget gamePadWidget;
    gamePadWidget.show();



    return app.exec();
}
