#ifndef PRINT_H
#define PRINT_H

#include <QWidget>

namespace Ui {
class Print;
}

class Print : public QWidget
{
    Q_OBJECT

public:
    explicit Print(QWidget *parent = nullptr);
    ~Print();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Print *ui;
};

#endif // PRINT_H
