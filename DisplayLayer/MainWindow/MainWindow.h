#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "../Player/Player.h"
#include "ComThread.h"
#include "DisplayLayer/GamePad/gamepadwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void slot_widget(QWidget*);
    void slot_widget1(QWidget*);
    void slot_a(uint32_t);
    void slot_connect();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void player_delete_later(Player*);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow          *ui;
    GamePadWidget           *gamePadWidget;
    Player                  *player;
    Player                  *player1;
    QWidget                 *widget;
    QWidget                 *widget1;
    QWidget                 *m_widget;
    ComThread               *comThread;


};

#endif // MAINWINDOW_H
