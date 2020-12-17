#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webContext = new WebContext(this);
    webChannel = new QWebChannel(this);
    webChannel->registerObject("context",webContext);

    view = new QWebEngineView(ui->widgetMap);


    //view->load(QUrl("file:///D:/AUV/Gui/test.html"));

    view->load(QUrl("file:///D:/AUV/Gui/map.html"));
    view->page()->setWebChannel(webChannel);

    view->resize(ui->widgetMap->size());
    view->show();

    ui->lineEdit->setText("2");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_pushbtn()));
    connect(ui->actionGPS,SIGNAL(triggered()),this,SLOT(slot_actionGPS()));

}

MainWindow::~MainWindow()
{
    view->close();
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{

}

void MainWindow::slot_pushbtn()
{
    static int id = 0;
    QJsonObject json;
    json["cmd"] = ui->lineEdit->text().toInt();
    json["a"] = 14;
    json["b"] = 3.336;
    json["c"] = "sdef";
    json["id"] = id++;
    webContext->setProperty("content", json);
    //emit webContext->contentChanged("I love you too!");
    //webContext->setProperty("content","I love you too!");
}

void MainWindow::slot_actionGPS()
{
    static GPSDialog* gpsDialog = nullptr;
    if(!gpsDialog)
    {
        gpsDialog = new GPSDialog(this);
    }
    gpsDialog->show();
}
