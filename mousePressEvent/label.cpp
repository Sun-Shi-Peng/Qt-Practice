#include "label.h"

Label::Label(QWidget* parent):QLabel(parent) {}

void Label::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        qDebug()<<"按下左键";
    }else if(event->button()==Qt::RightButton){
        qDebug()<<"按下右键";
    }else{
        qDebug()<<"按下中键";
    }
    // 当前 event 对象就包含了鼠标点击位置的坐标
    qDebug()<<event->x()<<","<<event->y();              // 以控件左上角为原点，相对位置
    qDebug()<<event->globalX()<<","<<event->globalY();  // 以屏幕左上角为原点，绝对坐标
}
