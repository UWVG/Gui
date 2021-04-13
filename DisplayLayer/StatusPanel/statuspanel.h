#ifndef STATUSPANEL_H
#define STATUSPANEL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StatusPanel; }
QT_END_NAMESPACE

class StatusPanel : public QWidget
{
    Q_OBJECT

public:
    StatusPanel(QWidget *parent = nullptr);
    ~StatusPanel();

private:
    Ui::StatusPanel *ui;
};
#endif // STATUSPANEL_H
