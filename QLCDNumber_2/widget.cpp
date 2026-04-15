#include "widget.h"
#include "ui_widget.h"
#include <thread>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 无法实现，Qt 禁止其他线程直接修改界面
    std::thread t([this](){
        int value=ui->lcdNumber->intValue();
        while(true)
        {
            // 先休眠1s
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if(value<=0)
            {
                break;
            }
            value-=1;
            ui->lcdNumber->display(value);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
