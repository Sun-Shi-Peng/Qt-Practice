#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "thread.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
    Thread t1;
    Thread t2;
};
#endif // WIDGET_H
