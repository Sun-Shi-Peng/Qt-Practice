#include "thread.h"
#include <QMutexLocker>
QMutex Thread::mutex;
int Thread::num=0;
Thread::Thread() {}

void Thread::run()
{
    for(int i=0;i<50000;i++)
    {
        QMutexLocker locker(&mutex);
        // mutex.lock();
        num++;
        // mutex.unlock();
    }
}
