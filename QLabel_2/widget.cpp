#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QResizeEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 先把QLabel设置成和窗口一样大，并且把这个QLabel左上角设置到窗口的左上角
    // 让整个QLabel铺满整个窗口
    QRect windowRect=this->geometry();
    ui->label->setGeometry(0,0,windowRect.width(),windowRect.height());

    QPixmap pixmap(":/11.png");
    ui->label->setPixmap(pixmap);
    // 图片大小可能小于窗口大小，铺不满->启动自动拉伸
    ui->label->setScaledContents(true); // 这个设置是一次性的，运行起来之后再拉伸就不会跟着变化了

    // 当用户拖拽修改窗口大小的时候，就会连续触发 resize 事件(resizeEvent)
}

Widget::~Widget()
{
    delete ui;
}

// 此处的形参event是非常有用的，包含了触发这个resize事件这一时刻，窗口的尺寸的数值
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() <<event->size();
    ui->label->setGeometry(0,0,event->size().width(),event->size().height());
}
