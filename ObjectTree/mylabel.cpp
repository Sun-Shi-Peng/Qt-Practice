#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    qDebug()<<"MyLabel 被销毁！";
}
