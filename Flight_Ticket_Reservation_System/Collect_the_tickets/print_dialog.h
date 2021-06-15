#ifndef PRINT_DIALOG_H
#define PRINT_DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>

namespace Ui {
class Print_Dialog;
}

class Print_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Print_Dialog(QWidget *parent = nullptr);
    void Send_Data(QString s1,QString s2,QString s3,QString s4,QString s5,QString s6,QString s7);
    ~Print_Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Print_Dialog *ui;
};

#endif // PRINT_DIALOG_H
