#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 把这个选项设置为true，才能够追踪鼠标的移动位置
    this->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

// 鼠标移动不同于鼠标按下，因为随便移动一下鼠标，就会产生大量鼠标移动事件，当你进行捕获事件的时候，很容易卡顿之类的情况
// Qt为了保证程序流畅性，默认情况不会对鼠标移动进行追踪，除非显示告诉Qt要跟踪
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<event->x()<<","<<event->y();
}
