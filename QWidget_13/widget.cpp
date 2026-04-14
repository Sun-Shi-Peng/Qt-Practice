#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置两个按钮的tooltips
    ui->pushButton_yes->setToolTip("yes");
    ui->pushButton_yes->setToolTipDuration(2000);

    ui->pushButton_no->setToolTip("no");
    ui->pushButton_no->setToolTipDuration(2000);
}

Widget::~Widget()
{
    delete ui;
}
