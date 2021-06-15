#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/image/image/logo.png"));
    setWindowTitle("机票预订系统");
    tableView_style();
    Button_style();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tableView_style()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("FTRS.db");
    bool ok = db.open();
    if(ok)
    {
    qDebug()<<"connect normal";
    }
    else
    {
    qDebug()<<"connect error!";
    }

    query_model = new QSqlQueryModel;
    //创建模型
    model = new QSqlTableModel(this);
    model->setTable("Customer_information");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);// 设置编辑策略
    model->select(); //选取整个表的所有行
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"性别");
    model->setHeaderData(2,Qt::Horizontal,"工作单位");
    model->setHeaderData(3,Qt::Horizontal,"身份证号");
    model->setHeaderData(4,Qt::Horizontal,"航班号");
    model->setHeaderData(5,Qt::Horizontal,"旅行时间");
    model->setHeaderData(6,Qt::Horizontal,"目的地");
    ui->tableView->setModel(model);
    ui->tableView_2->setModel(model);
    ui->tableView_3->setModel(model);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,250);
    ui->tableView->setColumnWidth(3,200);
    ui->tableView->setColumnWidth(4,150);
    ui->tableView->setColumnWidth(5,150);
    ui->tableView->setColumnWidth(6,100);
    ui->tableView_2->setColumnWidth(0,100);
    ui->tableView_2->setColumnWidth(1,100);
    ui->tableView_2->setColumnWidth(2,250);
    ui->tableView_2->setColumnWidth(3,200);
    ui->tableView_2->setColumnWidth(4,150);
    ui->tableView_2->setColumnWidth(5,150);
    ui->tableView_2->setColumnWidth(6,100);
    ui->tableView_3->setColumnWidth(0,100);
    ui->tableView_3->setColumnWidth(1,100);
    ui->tableView_3->setColumnWidth(2,250);
    ui->tableView_3->setColumnWidth(3,200);
    ui->tableView_3->setColumnWidth(4,150);
    ui->tableView_3->setColumnWidth(5,150);
    ui->tableView_3->setColumnWidth(6,100);
    ui->tableView->show();
    ui->tableView_2->show();
    ui->tableView_3->show();

}
void MainWindow::Button_style()
{
    ui->widget_2->setStyleSheet("QPushButton{background-color: rgb(48, 66, 103);border:none;color:rgb(255, 255, 255);}"
                                  "QPushButton:hover{background-color: #2789EE;border:none;color:rgb(255, 255, 255);font:bold Microsoft YaHei;}"
                                  "QPushButton:checked{background-color: #2789EE;border:none;color:rgb(255, 255, 255);font:bold Microsoft YaHei;}");
}
void MainWindow::on_pushButton_clicked()
{
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->stackedWidget->setCurrentIndex(3);
}
//查找
void MainWindow::on_pushButton_5_clicked()
{
    QString str = ui->lineEdit->text();
    model->setFilter(tr("name like '%1'").arg("%"+str+"%"));
    model->select();
}

void MainWindow::on_pushButton_9_clicked()
{
    QString str = ui->lineEdit_2->text();
    model->setFilter(tr("name like '%1'").arg("%"+str+"%"));
    model->select();
}

void MainWindow::on_pushButton_12_clicked()
{
    QString str = ui->lineEdit_3->text();
    model->setFilter(tr("name like '%1'").arg("%"+str+"%"));
    model->select();
}
//添加
void MainWindow::on_pushButton_8_clicked()
{
    Add_Dialog a;
    a.exec();
    model->select();
}
//刷新
void MainWindow::on_pushButton_6_clicked()
{
    model->select();
}
//保存
void MainWindow::on_pushButton_7_clicked()
{
    model->database().transaction();
    if(model->submitAll()){
        model->database().commit(); //提交
    }
    else{
        model->database().rollback();// 撤回
        QMessageBox::warning(this,"数据库错误",tr("数据库错误: %1").arg(model->lastError().text()));
    }
}
//取消预订
void MainWindow::on_pushButton_13_clicked()
{
    int rowIndex = ui->tableView_3->currentIndex().row();

    if(rowIndex>=0)
    {
        model->removeRow(rowIndex);
        int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),
                                     QMessageBox::Yes,QMessageBox::No);

        if(ok == QMessageBox::No)
          {
            model->revertAll(); //如果不删除，则撤销
          }
        else model->submitAll(); //否则提交，在数据库中删除该行
    }
    else
    {
        QMessageBox::critical(this,tr("错误"),tr("未选择行！"),QMessageBox::Ok);
    }
}
//打印
void MainWindow::on_pushButton_11_clicked()
{
    query_model->setQuery(tr("SELECT * FROM Customer_information"));
    int rowIndex = ui->tableView_2->currentIndex().row();
    QVariant s1 = query_model->data(query_model->index(rowIndex,0));
    QVariant s2 = query_model->data(query_model->index(rowIndex,1));
    QVariant s3 = query_model->data(query_model->index(rowIndex,2));
    QVariant s4 = query_model->data(query_model->index(rowIndex,3));
    QVariant s5 = query_model->data(query_model->index(rowIndex,4));
    QVariant s6 = query_model->data(query_model->index(rowIndex,5));
    QVariant s7 = query_model->data(query_model->index(rowIndex,6));

    if(rowIndex>=0)
    {
        printDialog p;
        p.data_transfer(s1.toString(),s2.toString(),s3.toString(),s4.toString(),s5.toString(),s6.toString(),s7.toString());
        p.exec();
    }
    else
    {
        QMessageBox::critical(this,tr("错误"),tr("未选择行！"),QMessageBox::Ok);
    }
}
