#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QDialog>

namespace Ui {
class printDialog;
}

class printDialog : public QDialog
{
    Q_OBJECT

public:
    QString name;
    QString sex;
    QString work_units;
    QString id;
    QString number;
    QString travel_time;
    QString destination;
    explicit printDialog(QWidget *parent = nullptr);
    void data_transfer(QString dname,QString dsex,QString dwork_units,QString did,QString dnumber,QString dtravel_time,QString ddestination);
    ~printDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::printDialog *ui;
};

#endif // PRINTDIALOG_H
