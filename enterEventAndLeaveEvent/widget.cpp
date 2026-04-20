#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 确保界面上的label是咱们自己定义的label类才行

}

Widget::~Widget()
{
    delete ui;
}
