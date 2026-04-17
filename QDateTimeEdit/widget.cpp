#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 1.先获取到两个输入框之间的时间都是啥
    QDateTime timeOld=ui->dateTimeEdit->dateTime();
    QDateTime timeNew=ui->dateTimeEdit_2->dateTime();
    qDebug()<<timeOld<<timeNew;
    // 2.计算日期差值
    int seconds=timeOld.secsTo(timeNew);
    // 3.把秒数换算成小时
    int hours=(seconds/3600)%24;    // 重点关心多出来的零头
    int days=(seconds/3600)/24;
    // 4.把计算结果放到label中
    ui->label->setText(QString("我已经学习了 ")+QString::number(days)+
                       QString(" 天零 ")+QString::number(hours)+QString(" 小时"));
}