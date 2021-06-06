#include "printdialog.h"
#include "ui_printdialog.h"

#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QSqlQueryModel>

printDialog::printDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::printDialog)
{
    ui->setupUi(this);
}

printDialog::~printDialog()
{
    delete ui;
}
void printDialog::data_transfer(QString dname,QString dsex,QString dwork_units,QString did,QString dnumber,QString dtravel_time,QString ddestination)
{
    name = dname;
    sex = dsex;
    work_units = dwork_units;
    id = did;
    number = dnumber;
    travel_time = dtravel_time;
    destination = ddestination;
    ui->label->setText(name);
    ui->label_2->setText(sex);
    ui->label_3->setText(work_units);
    ui->label_4->setText(id);
    ui->label_5->setText(travel_time);
    ui->label_6->setText(destination);
    ui->label_7->setText(number);
    //价格
    QSqlQueryModel *query_model_2;
    query_model_2 = new QSqlQueryModel;
    query_model_2->setQuery(tr("SELECT price from Flight_information where number = '%1'").arg(number));
    QVariant text_3 = query_model_2->data(query_model_2->index(0,0));
    ui->label_17->setText(text_3.toString());
}

void printDialog::on_buttonBox_accepted()
{
    // 生成PDF文件
        QPrinter printer;
        QPixmap image;
    //    QPainter painter(&printer);
        image = image.grabWidget(this,40,50,740,580);
        QString fileName = QFileDialog::getSaveFileName(this, tr("导出PDF文件"),
                                                        QString(), "*.pdf");
        if (!fileName.isEmpty()) {

            // 如果文件后缀为空，则默认使用.pdf
            if (QFileInfo(fileName).suffix().isEmpty())
            fileName.append(".pdf");
            printer.setOutputFileName(fileName);
            QPixmap pixmap=QPixmap::grabWidget(ui->widget,ui->widget->rect()); //抓取界面widget区域，可以抓取任意控件区域，Qt5推荐新的API QWidget::grab
            QPainter painter;
            painter.begin(&printer);
            QRect rect=painter.viewport(); //获取painter的视口区域
            int factor=rect.width()/pixmap.width(); //计算painter视口区域与抓取图片区域的尺寸比例因子
            painter.scale(factor*1.0,factor*1.0); //绘制时按照比例因子放大
            painter.drawPixmap(10,10,pixmap); //按照坐标画图

            printer.setPageSize(QPrinter::A4);
            printer.setOutputFormat(QPrinter::PdfFormat);
        }
}
