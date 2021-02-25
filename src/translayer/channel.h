#ifndef TRANSLAYER_CHANNEL_H
#define TRANSLAYER_CHANNEL_H

#include "translayer/eventloop.h"

namespace sparrow {

// Channel 是 epoll_wait 时 event.data.ptr 这个指针指向的数据结构, 用来做事件的处理
// 一个有了事件的连接, 就会对应一个 active 的 channel, 然后我们调用 channel 的 handleEvent() 来处理事件
// acceptor 有一个 channel, 每一个 connection 也有一个 channel
// 在eventloop 使用 poller->poll() 的循环过程中, 我们将 channel 挂到 poller 上, 使得 poller 可以监听 channel
class Channel
{
public:
    Channel(EventLoop* loop, int fd);
    ~Channel();
private:
    EventLoop* loop_;
    const int fd_;  // 连接套接字

    int events{};  // 对 fd 感兴趣的事件
    int revents{};  // 收到的事件

};

} // namespace sparrow

#endif