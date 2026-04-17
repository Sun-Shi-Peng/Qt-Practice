#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 往里面添加一些元素
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");
    ui->listWidget->addItem(new QListWidgetItem("Go"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_insert_clicked()
{
    const QString& text=ui->lineEdit->text();
    ui->listWidget->addItem(text);
}

void Widget::on_pushButton_delete_clicked()
{
    int row=ui->listWidget->currentRow();
    if(row<0)
        return;
    ui->listWidget->takeItem(row);
}


void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // 通过这个槽函数，感知到变化
    if(current!=nullptr)
    {
        qDebug()<<"当前选中的元素："<<current->text();
    }
    if(previous!=nullptr)
    {
        qDebug()<<"上次选中的元素："<<previous->text();
    }
}

