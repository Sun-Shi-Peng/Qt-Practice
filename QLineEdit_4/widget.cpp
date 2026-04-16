#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始状态下，输入框按照密码方式来显示
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        // true则是“显示密码”状态，就把输入框的显示模式，设为Normal
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }else{
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}

