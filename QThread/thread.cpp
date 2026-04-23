#include "thread.h"

Thread::Thread() {}

void Thread::run()
{
    // 不能直接在run中访问界面内容
    // 虽然不能修改界面，但是可以针对事件进行计时
    // 当每到一秒钟的时候，通过信号槽，来通知主线程，负责更新线程
    for(int i=0;i<10;i++){
        // sleep 本身是 QThread 的成员函数，就可以直接调用
        sleep(1);
        // 发送一个信号，通知主线程
        emit notify();
    }
}
