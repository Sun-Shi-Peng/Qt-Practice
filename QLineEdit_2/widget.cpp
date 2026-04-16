#include "widget.h"
#include "ui_widget.h"

#include <QRegExpValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 需要给单行输入框设置验证器，基于正则表达式来实现
    QRegExp regExp("^1\\d{10}");
    // ^1表示以1开头；\d表示数字，为了在C++字符串中使用，需要写作\\d；{10}表示前面的内容重复出现10次
    ui->lineEdit->setValidator(new QRegExpValidator(regExp)); // 只是注册了一个验证器
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textEdited(const QString &text)
{
    // 第一个参数是要验证的字符串，参数类型是 QString&，不是const
    QString content=text;
    int pos=0;
    if(ui->lineEdit->validator()->validate(content,pos))   // 验证是否符合要求
    {
        // 验证通过
        ui->pushButton->setEnabled(true);
    }else{
        ui->pushButton->setEnabled(false);
    }
}

