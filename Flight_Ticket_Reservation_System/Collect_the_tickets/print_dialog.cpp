#include "print_dialog.h"
#include "ui_print_dialog.h"

Print_Dialog::Print_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Print_Dialog)
{
    ui->setupUi(this);
    ui->widget->setAutoFillBackground(true);
    QPalette palette = ui->widget->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/image/330683-1P102103I575.jpg").scaled(ui->widget->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));// 使用平滑的缩放方式
    ui->widget->setPalette(palette);
}

Print_Dialog::~Print_Dialog()
{
    delete ui;
}
void Print_Dialog::Send_Data(QString s1,QString s2,QString s3,QString s4,QString s5,QString s6,QString s7)
{
    ui->label->setText(s1);
    ui->label_2->setText(s2);
    ui->label_3->setText(s3);
    ui->label_4->setText(s4);
    ui->label_5->setText(s5);
    ui->label_6->setText(s6);
    ui->label_7->setText(s7);
}

void Print_Dialog::on_pushButton_clicked()
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

     this->reject();
}
