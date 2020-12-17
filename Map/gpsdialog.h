#ifndef GPSDIALOG_H
#define GPSDIALOG_H

#include <QDialog>

namespace Ui {
class GPSDialog;
}

class GPSDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GPSDialog(QWidget *parent = nullptr);
    ~GPSDialog();

private slots:


private:
    Ui::GPSDialog *ui;
};

#endif // GPSDIALOG_H
