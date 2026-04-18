#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* menuBar=new QMenuBar();
    this->setMenuBar(menuBar);

    QMenu* menu=new QMenu("菜单");
    menu->setIcon(QIcon(":/1.png"));
    menuBar->addMenu(menu);

    QAction* action1=new QAction("菜单项1");
    action1->setIcon(QIcon(":/1.png"));
    QAction* action2=new QAction("菜单项2");
    action2->setIcon(QIcon(":/2.png"));
    menu->addAction(action1);
    menu->addAction(action2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
