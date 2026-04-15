#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建一个图标对象
    QIcon icon(":/11.png");
    // 设置图标
    ui->pushButton->setIcon(icon);
    // 设置图标尺寸
    ui->pushButton->setIconSize(QSize(50,50));
}

Widget::~Widget()
{
    delete ui;
}
