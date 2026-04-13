#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 建立连接，不代表信号发出来了！！
    connect(this,&Widget::mySignal,this,&Widget::handleMySignal);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal()
{
    this->setWindowTitle("处理自定义信号");
}

void Widget::on_pushButton_clicked()
{
    // 发送出自定义的信号
    // 发送信号的操作，也可以在任意合适的代码中，不一定非得在构造函数里
    emit mySignal();
}

