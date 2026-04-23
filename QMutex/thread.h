#ifndef THREAD_H
#define THREAD_H
#include <QMutex>
#include <QThread>
#include <QWidget>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    // 添加一个 static 成员
    static int num;
    // 创建锁对象,多个线程进行加锁的对象，得是同一个对象
    // 不同的对象，此时不会产生锁的互斥，也就无法把并发执行变成串行执行，也就无法解决上述问题
    static QMutex mutex;

    void run();
};

#endif // THREAD_H
