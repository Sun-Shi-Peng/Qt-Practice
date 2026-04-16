#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始化第一个输入框，用来输入姓名
    ui->lineEdit_name->setPlaceholderText("请输入姓名");
    ui->lineEdit_name->setClearButtonEnabled(true);

    // 初始化第二个输入款，用来输入密码
    ui->lineEdit_name_password->setPlaceholderText("请输入密码");
    ui->lineEdit_name_password->setClearButtonEnabled(true);
    // 把显示模式设置为密码格式
    ui->lineEdit_name_password->setEchoMode(QLineEdit::Password);

    // 初始化第三个输入款
    ui->lineEdit_name_phone->setPlaceholderText("请输入电话密码");
    ui->lineEdit_name_phone->setClearButtonEnabled(true);
    // 手机号码是有固定格式的,此处的0表示一个数字
    ui->lineEdit_name_phone->setInputMask("000-0000-0000");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_submit_clicked()
{
    QString gender=ui->radioButton_male->isChecked()?"男":"女";
    qDebug()<<"姓名："<<ui->lineEdit_name->text()
             <<"密码："<<ui->lineEdit_name_password->text()
             <<"姓名："<<gender
             <<"电话："<<ui->lineEdit_name_phone->text();
}

