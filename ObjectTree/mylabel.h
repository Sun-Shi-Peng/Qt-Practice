#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
public:
    //构造函数需要带QWidget*版本的
    //这样才能确保咱们自己的对象能加到对象树
    MyLabel(QWidget *parent);
    ~MyLabel();
};

#endif // MYLABEL_H
