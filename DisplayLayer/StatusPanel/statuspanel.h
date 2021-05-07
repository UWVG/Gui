#ifndef STATUSPANEL_H
#define STATUSPANEL_H

#include <QWidget>
#include "radiosignalstrength.h"

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
    RadioSignalStrength *radioSignalStrength;
private slots:
    void slot_signal_master(struct Signal);
    void slot_signal_slave(struct Signal);
};
#endif // STATUSPANEL_H
