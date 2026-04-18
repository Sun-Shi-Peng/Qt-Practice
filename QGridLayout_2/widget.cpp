#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建6个按钮，使用网格布局按照2*3的方式来排列
    QPushButton* button1=new QPushButton("按钮1");
    QPushButton* button2=new QPushButton("按钮2");
    QPushButton* button3=new QPushButton("按钮3");
    QPushButton* button4=new QPushButton("按钮4");
    QPushButton* button5=new QPushButton("按钮5");
    QPushButton* button6=new QPushButton("按钮6");

    // 创建一个网格布局管理器，把这些控件添加进去
    QGridLayout* layout=new QGridLayout();
    layout->addWidget(button1,0,0);
    layout->addWidget(button2,0,1);
    layout->addWidget(button3,0,2);
    layout->addWidget(button4,1,0);
    layout->addWidget(button5,1,1);
    layout->addWidget(button6,1,2);

    this->setLayout(layout);

    // 设置水平拉伸系数
    layout->setColumnStretch(0,0);  //第0列的拉伸系数为0
    layout->setColumnStretch(1,1);
    layout->setColumnStretch(2,2);

}

Widget::~Widget()
{
    delete ui;
}
