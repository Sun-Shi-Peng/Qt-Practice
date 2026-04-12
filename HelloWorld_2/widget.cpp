#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //更推荐按这种在堆上创建的方式
    QLabel *label=new QLabel(this); //给当前这个label对象指定一个父对象
    label->setText("hello world");
    // QLabel label;
    // label.setText("hello");
}

Widget::~Widget()
{
    delete ui;
}
