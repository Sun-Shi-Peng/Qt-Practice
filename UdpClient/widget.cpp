#include "widget.h"
#include "ui_widget.h"
#include <QNetworkDatagram>

// 定义两个常量，描述服务器的 地址 和 端口
const QString& SERVER_IP="127.0.0.1";
// 端口号本质是一个2字节的无符号整数，本质上quint16就是一个 unsigned short（C++里面没有，没有明确规定是2个字节）
const quint16 SERVER_PORT=9090;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket=new QUdpSocket(this);
    // 修改窗口标题，方便区分是一个客户端程序
    this->setWindowTitle("客户端");

    // 用过信号槽来处理服务器返回的数据
    connect(socket,&QUdpSocket::readyRead,this,&Widget::processResponse);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 1.获取输入框的内容
    const QString& text=ui->lineEdit->text();
    // 2.构造UDP请求数据
    QNetworkDatagram requestDatagram(text.toUtf8(),QHostAddress(SERVER_IP),SERVER_PORT);
    // 3.发送请求数据
    socket->writeDatagram(requestDatagram);
    // 4.把发送的请求也添加到列表框中
    ui->listWidget->addItem("客户端说: "+text);
    // 5.清空输入框
    ui->lineEdit->setText("");
}

void Widget::processResponse()
{
    // 通过这个函数来处理收到的响应
    // 1.读取到响应数据
    const QNetworkDatagram& responseDatagram=socket->receiveDatagram();
    QString response=responseDatagram.data();
    // 大多数时候能用引用尽量用引用，需要类型转换时大多是使用值类型

    // 2.把响应数据显示到界面上
    ui->listWidget->addItem("服务器说: "+response);
}