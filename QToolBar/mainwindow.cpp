#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolBar>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 工具栏是需要手动创建出来的，自身不会自动创建
    QToolBar* toolBar=new QToolBar;
    this->addToolBar(toolBar);

    QAction* action1=new QAction("保存");
    QAction* action2=new QAction("打开");
    action1->setIcon(QIcon(":/1.png"));
    action2->setIcon(QIcon(":/2.png"));
    toolBar->addAction(action1);
    toolBar->addAction(action2);

    connect(action1,&QAction::triggered,this,&MainWindow::handle1);
    connect(action2,&QAction::triggered,this,&MainWindow::handle2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle1()
{
    qDebug()<<"handle1";
}

void MainWindow::handle2()
{
    qDebug()<<"handle2";
}
