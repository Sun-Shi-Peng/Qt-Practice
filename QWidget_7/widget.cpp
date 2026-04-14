#include "widget.h"
#include "ui_widget.h"

#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置图标
    // 优先在栈上创建图标， QIcon 自身是一个比较小的对象，创建出来之后就是要设置到某个 QWidget 里面。QIcon 对象本身是否释放影响图标最终的显示
    // 绝对路径的方式引入图片是不科学的，使用相对路径更好，避免
    QIcon icon(":/11.png");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}
