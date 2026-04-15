#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置一个初始值
    ui->lcdNumber->display(10);

    // 创建一个QTimer实例
    timer=new QTimer(this);
    // 把QTimer的timeout信号和槽函数进行链接
    connect(timer,&QTimer::timeout,this,&Widget::handle);
    // 启动定时器，参数是触发timeout的周期，单位是ms
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    // 拿到LCDNumber中的数字
    int value=ui->lcdNumber->intValue();
    if(value<=0)
    {
        // 数字减到0了，停止定时器
        timer->stop();
        return;
    }
    ui->lcdNumber->display(--value);
}
