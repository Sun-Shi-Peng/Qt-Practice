#include "widget.h"
#include "ui_widget.h"
#include <fstream>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 读取文件内容，把文件中的每一行读取出来，作为一个 ComboBox 的选项
    std::ifstream file("C:\\Users\\28714\\Desktop\\config.txt");
    if(!file.is_open()){
        qDebug()<<"文件打开失败";
        return;
    }
    // 按行来读取文本内容
    // getline 函数
    std::string line;
    while(std::getline(file,line)){
        // 取到每一行的内容，设置到下拉框中
        ui->comboBox->addItem(QString::fromStdString(line));
    }
    file.close();
}

Widget::~Widget()
{
    delete ui;
}
