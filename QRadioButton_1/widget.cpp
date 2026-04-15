#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 添加一个默认的选项
    ui->radioButton_male->setCheckable(true);
    ui->label->setText("您选择的性别为：男");

    // 禁用其他选项
    ui->radioButton_other->setCheckable(false); // 没被选中但是依旧可以响应点击事件
    // ui->radioButton_other->setDisabled(true);
    ui->radioButton_other->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_radioButton_male_clicked()
{
    // 把界面上的 label 的内容进行更新
    ui->label->setText("您选择的性别为：男");
}

void Widget::on_radioButton_female_clicked()
{
    ui->label->setText("您选择的性别为：女");
}

void Widget::on_radioButton_other_clicked()
{
    ui->label->setText("您选择的性别为：其他");
}

