#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置对齐方式
    ui->label->setText("这是一段文本");
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //水平居中、垂直居中

    // 设置自动换行
    ui->label_2->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_2->setWordWrap(true); // 自动换行

    // 设置缩进，不仅仅是首行缩进
    ui->label_3->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50); // 单位是像素,即使文本换行后续的行也会缩进

    // 设置边距
    ui->label_4->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_3->setWordWrap(true);
    ui->label_4->setMargin(55);
}

Widget::~Widget()
{
    delete ui;
}
