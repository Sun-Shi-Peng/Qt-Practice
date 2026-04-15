#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置这些按钮的图标
    ui->pushButton_target->setIcon(QIcon(":/image/11.png"));
    ui->pushButton_target->setIconSize(QSize(50,50));

    ui->pushButton_up->setIcon(QIcon(":/image/up"));

    ui->pushButton_down->setIcon(QIcon(":/image/down"));

    ui->pushButton_left->setIcon(QIcon(":/image/left"));

    ui->pushButton_right->setIcon(QIcon(":/image/right"));

    // 直接通过按键名字设置，虽然简单但容易写错
    // ui->pushButton_up->setShortcut(QKeySequence("w"));
    // ui->pushButton_left->setShortcut(QKeySequence("a"));
    // ui->pushButton_right->setShortcut(QKeySequence("d"));
    // ui->pushButton_down->setShortcut(QKeySequence("s"));

    // 还可以通过按键的枚举来设置按键快捷键
    // ui->pushButton_up->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_W));   //ctrl+w组合键
    ui->pushButton_up->setShortcut(QKeySequence(Qt::Key_W));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));

    //开启鼠标低级的连发功能（键盘的连发功能默认就是支持的）
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_up_clicked()
{
    // 获取target的位置
    QRect rect=ui->pushButton_target->geometry();
    // 基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x(),rect.y()-5,rect.width(),rect.height());
}


void Widget::on_pushButton_left_clicked()
{
    // 获取target的位置
    QRect rect=ui->pushButton_target->geometry();
    // 基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}


void Widget::on_pushButton_right_clicked()
{
    // 获取target的位置
    QRect rect=ui->pushButton_target->geometry();
    // 基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x()+5,rect.y(),rect.width(),rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    // 获取target的位置
    QRect rect=ui->pushButton_target->geometry();
    // 基于上次的位置，设置新的位置
    ui->pushButton_target->setGeometry(rect.x(),rect.y()+5,rect.width(),rect.height());
}

