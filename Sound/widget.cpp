#include "widget.h"
#include "ui_widget.h"
#include <QSound>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    sound=new QSound(":/123.wav");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 在这里进行音频播放
    sound->play();
}

