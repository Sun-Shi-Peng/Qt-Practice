#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout* layout=new QHBoxLayout();
    this->setLayout(layout);

    QPushButton* button1=new QPushButton("按钮1");
    QPushButton* button2=new QPushButton("按钮2");

    // 创建spacer是两个按钮之间存在空白
    QSpacerItem* spacer=new QSpacerItem(200,20);

    // 当前是要把空白添加到两个按钮之间，此处add的顺序就是把addSpacerItem放到中间了
    layout->addWidget(button1);
    layout->addSpacerItem(spacer);
    layout->addWidget(button2);
}

Widget::~Widget()
{
    delete ui;
}
