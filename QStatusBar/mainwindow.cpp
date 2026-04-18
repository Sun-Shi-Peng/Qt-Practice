#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 存在就获取，不存在就创建
    QStatusBar* statusBar=this->statusBar();
    // 如果状态栏没有被创建，这样的设置是必要的
    // 如果状态栏已经在窗口中存在，这样的设置意义不大，但是也没副作用，仍然保留
    this->setStatusBar(statusBar);

    // 显示一个临时的信息
    // statusBar->showMessage("这是一个状态消息",3000);    // 3000ms后消失，可以不设置一直存在

    // 给状态栏中添加子控件
    // addWidget从左往右添加，addPermanentWidget从右往左添加
    QLabel* label1=new QLabel("这是一个 QLabel");
    statusBar->addWidget(label1);   // 可以指定一个拉伸系数

    // QLabel* label2=new QLabel("这是另一个 QLabel");
    // statusBar->addWidget(label2);

    QProgressBar* progressBar=new QProgressBar();
    progressBar->setRange(0,100);
    progressBar->setValue(50);
    statusBar->addWidget(progressBar);

    QPushButton* button=new QPushButton("按钮");
    statusBar->addPermanentWidget(button);
}

MainWindow::~MainWindow()
{
    delete ui;
}
