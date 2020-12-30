#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DisplayLayer/GamePad/gamepadwidget.h"
#include "../Player/Player.h"
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
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void player_delete_later(Player*);

private:
    Ui::MainWindow          *ui;
    GamePadWidget           *gamePadWidget;
    Player                  *player;
    Player                  *player1;
    QWidget                 *widget;
    QWidget                 *widget1;
    QWidget                 *m_widget;
};

#endif // MAINWINDOW_H
