#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建6个按钮，按照 3*2 的方式进行排列
    QPushButton* button1=new QPushButton("按钮1");
    QPushButton* button2=new QPushButton("按钮2");
    QPushButton* button3=new QPushButton("按钮3");
    QPushButton* button4=new QPushButton("按钮4");
    QPushButton* button5=new QPushButton("按钮5");
    QPushButton* button6=new QPushButton("按钮6");

    // 先让按钮能自由拉伸
    button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // 创建layout并把按钮添加进去
    QGridLayout* layout=new QGridLayout();
    layout->addWidget(button1,0,0);
    layout->addWidget(button2,0,1);
    layout->addWidget(button3,1,0);
    layout->addWidget(button4,1,1);
    layout->addWidget(button5,2,0);
    layout->addWidget(button6,2,1);

    // 把layout设置到窗口中
    this->setLayout(layout);

    // 设置拉伸系数
    layout->setRowStretch(0,1); // 设置第一列拉伸系数为0
    layout->setRowStretch(1,1);
    // 这里没有拉伸，是因为 SizePolicy 起到的影响，SizePolicy 限制了最大最小值
    layout->setRowStretch(2,2);
}

Widget::~Widget()
{
    delete ui;
}
