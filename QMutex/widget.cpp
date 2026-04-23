#include "widget.h"
#include "ui_widget.h"
#include "thread.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    t1.start();
    t2.start();

    // 让主线程等待这俩线程执行结束
    t1.wait();
    t2.wait();

    // 打印结果
    qDebug()<<Thread::num;
}

Widget::~Widget()
{
    delete ui;
}
