#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button1=new QPushButton("按钮1");
    QPushButton* button2=new QPushButton("按钮2");
    QPushButton* button3=new QPushButton("按钮3");
    QPushButton* button4=new QPushButton("按钮4");

    QGridLayout* layout=new QGridLayout();
    // layout->addWidget(button1,0,0);
    // layout->addWidget(button2,0,1);
    // layout->addWidget(button3,1,0);
    // layout->addWidget(button4,1,1);

    layout->addWidget(button1,0,0);
    layout->addWidget(button2,0,1);
    layout->addWidget(button3,0,2);
    layout->addWidget(button4,1,1);

    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
