#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *button=new QPushButton(this);
    button->setText("关闭窗口");
    button->move(300,500);

    connect(button,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{
    delete ui;
}
