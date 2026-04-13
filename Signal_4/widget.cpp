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

void Widget::handleMySignal(const QString& text)
{
    this->setWindowTitle(text);
}

void Widget::on_pushButton_clicked()
{
    // 发送出自定义的信号
    // 发送信号的操作，也可以在任意合适的代码中，不一定非得在构造函数里
    emit mySignal("把标题设置为标题1","");
}


void Widget::on_pushButton_2_clicked()
{
    emit mySignal("把标题设置为标题2","");
}

