#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWheelEvent>
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

    void wheelEvent(QWheelEvent* event);

private:
    Ui::Widget *ui;
    int total;
};
#endif // WIDGET_H
