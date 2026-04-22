#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key(); // 输出的是对应的数字
    if(event->key()==Qt::Key_A && event->modifiers()==Qt::ControlModifier){
        qDebug()<<"按下了 Ctrl+A 键";
    }
}
