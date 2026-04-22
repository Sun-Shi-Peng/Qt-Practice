#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 开启定时器事件
    // 此处timerId就是一个定时器的身份标识
    timerId=this->startTimer(1000); // 单位ms
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    // 如果程序存在多个定时器（startTimer 创建的定时器），此时每个定时器都会触发 timerEvent 函数
    // 先判断是不是想要的定时器出发的
    if(event->timerId()!=this->timerId){
        // 不是我们的定时器出发的直接忽略
        // 当前程序中只有这一个定时器
        return;
    }
    // 是自己要的定时器
    int value=ui->lcdNumber->intValue();
    if(value<=0){
        this->killTimer(this->timerId);
        return;
    }
    value-=1;
    ui->lcdNumber->display(value);
}
