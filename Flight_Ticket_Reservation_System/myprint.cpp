#include "myprint.h"
#include "ui_print.h"

#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

Print::Print(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Print)
{
    ui->setupUi(this);
}

Print::~Print()
{
    delete ui;
}

void Print::on_pushButton_clicked()
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
