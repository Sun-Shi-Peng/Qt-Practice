#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

class Label : public QLabel
{
public:
    Label(QWidget* parent);

    void mousePressEvent(QMouseEvent* event);
};

#endif // LABEL_H
