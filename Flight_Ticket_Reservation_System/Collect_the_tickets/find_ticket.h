#ifndef FIND_TICKET_H
#define FIND_TICKET_H
#include "print_dialog.h"
#include <QMainWindow>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QIcon>
#include <QDialog>

namespace Ui {
class Find_Ticket;
}

class Find_Ticket : public QDialog
{
    Q_OBJECT

public:
    explicit Find_Ticket(QDialog *parent = nullptr);
    ~Find_Ticket();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Find_Ticket *ui;
    QSqlTableModel *model;
    QSqlQueryModel *query_model;
};

#endif // FIND_TICKET_H
