#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 连接信号槽，通过槽函数更新界面
    connect(&thread,&Thread::notify,this,&Widget::handle);

    // 要启动下线程
    thread.start();
}

Widget::~Widget()
{
    thread.wait();

    delete ui;
}

void Widget::handle()
{
    // 此处修改界面内容
    int value=ui->lcdNumber->intValue();
    if(value<=0){
        return;
    }
    value-=1;
    ui->lcdNumber->display(value);
}
