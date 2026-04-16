#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ui->comboBox->addItem("牛肉堡");
    // ui->comboBox->addItem("鸡肉饼");
    // ui->comboBox->addItem("猪肉堡");

    // ui->comboBox_2->addItem("薯条");
    // ui->comboBox_2->addItem("鸡翅");
    // ui->comboBox_2->addItem("鸡块");

    // ui->comboBox_3->addItem("可乐");
    // ui->comboBox_3->addItem("雪碧");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug()<<ui->comboBox->currentText()<<","
             <<ui->comboBox_2->currentText()<<","
             <<ui->comboBox_3->currentText();
}

