#include "find_ticket.h"
#include "ui_find_ticket.h"

Find_Ticket::Find_Ticket(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Find_Ticket)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/image/find.png"));
    setWindowTitle("机票查询");
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
}

Find_Ticket::~Find_Ticket()
{
    delete ui;
}

void Find_Ticket::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    model->setFilter(tr("id like '%1'").arg("%"+str+"%"));
    model->select();
    QVariant text = model->data(model->index(0,0));
    QVariant text_1 = model->data(model->index(0,1));
    QVariant text_2 = model->data(model->index(0,2));
    QVariant text_3 = model->data(model->index(0,3));
    QVariant text_4 = model->data(model->index(0,4));
    QVariant text_5 = model->data(model->index(0,5));
    QVariant text_6 = model->data(model->index(0,6));
    Print_Dialog p;
    p.Send_Data(text.toString(),text_1.toString(),text_2.toString(),text_3.toString(),text_4.toString(),text_5.toString(),text_6.toString());
    p.exec();
}

void Find_Ticket::on_pushButton_2_clicked()
{
    this->reject();
}
