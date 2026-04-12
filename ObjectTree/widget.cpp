#include "widget.h"
#include "ui_widget.h"
#include "mylabel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 使用自己自己定义的MyLabel代替原来的QLabel，所谓的”继承“本质上是扩展，保持原有功能不变的基础上
    // 给对象扩展出一个
    MyLabel *label=new MyLabel(this);
    label->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}
