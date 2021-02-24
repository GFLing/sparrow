#ifndef TRANSLAYER_TCPSERVER_H
#define TRANSLAYER_TCPSERVER_H

#include <memory>

#include "base/inet_address.h"
#include "base/threadpool.h"
#include "translayer/eventloop.h"

namespace sparrow {

class TcpServer
{
public:

    // 是否设置 socket 的 SO_REUSEPORT 选项, 默认不设置.
    enum Option {
        kNoReusePort,
        kReusePort,
    };

    TcpServer(EventLoop* loop, InetAddress& listen_addr, std::string& name, Option opt = Option::kNoReusePort);
    ~TcpServer();

    // 设置线程池线程数量, 0 表示只有一个主线程, N表示线程池里的线程数量
    void SetThreadNum(int num);

private:
    EventLoop* accept_loop_;  // 监听主线程
    std::unique_ptr<TheradPool> thread_pool_;  // 线程池
};

}  // namespace sparrow

#endif  // TRANSLAYER_TCPSERVER_H