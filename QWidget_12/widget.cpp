#include "widget.h"
#include "ui_widget.h"

#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel* label=new QLabel(this);
    label->setText("这是一段文本");

    // 字体对象
    QFont font;
    font.setFamily("仿宋");
    font.setPixelSize(50);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(true);
    font.setStrikeOut(true);
    // 把 font 对象去设置到 label 中
    label->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}
