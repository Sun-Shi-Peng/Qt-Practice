#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QWidget>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    // 重要的目的是要重写父类的方法
    void run();
signals:
    void notify();
};

#endif // THREAD_H
