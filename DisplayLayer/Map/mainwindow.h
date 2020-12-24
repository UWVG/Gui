#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QJsonObject>
#include <QWebChannel>
#include "webcontext.h"
#include "gpsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent *);
private:
    Ui::MainWindow  *ui;
    QWebEngineView  *view;
    WebContext      *webContext;
    QWebChannel     *webChannel;

private slots:
    void slot_pushbtn();
    void slot_actionGPS();
};

#endif // MAINWINDOW_H
