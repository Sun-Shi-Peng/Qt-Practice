#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置随机种子，使用时间戳作为随机种子
    srand(time(nullptr));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_1_clicked()
{
    ui->label->setText("ssp!");
}


void Widget::on_pushButton_2_clicked()
{

}

// 鼠标按下（未抬起时）
void Widget::on_pushButton_2_pressed()
{
    // 点击这个按钮就把这个按钮挪走
    // 可以通过生成随机数的方式，来确定按钮的新位置

    // 获取当前窗口尺寸
    int width=this->geometry().width();
    int height=this->geometry().height();

    // 重新生成按钮的位置
    int x=rand()%width;
    int y=rand()%height;

    // 移动按钮位置
    ui->pushButton_2->move(x,y);
}

