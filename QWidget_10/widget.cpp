#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 访问到图片文件
    QPixmap pixmap(":/12.png");
    pixmap=pixmap.scaled(50,50);   //缩放图片

    // 构造光标对象
    // 默认情况下，鼠标点击时，相当于图片的左上角在进行点击
    QCursor cursor(pixmap,10,10);
    // 10,10 以图片左上角为0，0原点，找到10，10这个位置作为鼠标真正点击位置
    // 把光标设置进去
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}
