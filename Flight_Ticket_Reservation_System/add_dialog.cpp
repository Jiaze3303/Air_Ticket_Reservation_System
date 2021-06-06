#include "add_dialog.h"
#include "ui_add_dialog.h"

Add_Dialog::Add_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Dialog)
{
    ui->setupUi(this);
    query_model = new QSqlQueryModel;
    combox_Binddata();
}

Add_Dialog::~Add_Dialog()
{
    delete ui;
}

void Add_Dialog::on_buttonBox_accepted()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("FTRS.db");
    db.open();
    QSqlQuery query(db);
    int index = ui->comboBox_2->currentIndex();
    int index_2 = ui->comboBox->currentIndex();
    QString name = ui->lineEdit->text();
    QString sex = ui->comboBox_2->itemText(index);
    QString work_units = ui->lineEdit_2->text();
    QString id = ui->lineEdit_3->text();
    QString number = ui->comboBox->itemText(index_2);
    QString travel_time = ui->label_17->text();
    QString destination = ui->label_14->text();
    QString sql = "insert into Customer_information values(?,?,?,?,?,?,?)";
    query.prepare(sql);//sql语句预处理
    query.addBindValue(name);
    query.addBindValue(sex);
    query.addBindValue(work_units);
    query.addBindValue(id);
    query.addBindValue(number);
    query.addBindValue(travel_time);
    query.addBindValue(destination);
    query.exec();
}
void Add_Dialog::combox_Binddata()
{
    query_model->setQuery("SELECT * FROM Flight_information");
    for (int i = 0; i < query_model->rowCount(); i++) {
        QVariant text = query_model->data(query_model->index(i,0));
        ui->comboBox->addItem(text.toString());
    }
    ui->comboBox_2->addItem("男");
    ui->comboBox_2->addItem("女");
    ui->comboBox_2->addItem("外星人");
}

void Add_Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel *query_model_2;
    query_model_2 = new QSqlQueryModel;
    //航班号
    ui->label_18->setText(arg1);

    //出发地
    query_model_2->setQuery(tr("SELECT place_of_departure from Flight_information where number = '%1'").arg(arg1));
    QVariant text = query_model_2->data(query_model_2->index(0,0));
    ui->label_16->setText(text.toString());

    //目的地
    query_model_2->setQuery(tr("SELECT destination from Flight_information where number = '%1'").arg(arg1));
    QVariant text_2 = query_model_2->data(query_model_2->index(0,0));
    ui->label_14->setText(text_2.toString());

    //旅行时间
    query_model_2->setQuery(tr("SELECT travel_time from Flight_information where number = '%1'").arg(arg1));
    QVariant text_4 = query_model_2->data(query_model_2->index(0,0));
    ui->label_17->setText(text_4.toString());

    //价格
    query_model_2->setQuery(tr("SELECT price from Flight_information where number = '%1'").arg(arg1));
    QVariant text_3 = query_model_2->data(query_model_2->index(0,0));
    ui->label_15->setText(text_3.toString());

}
