#ifndef TRANSLAYER_ACCEPTOR_H
#define TRANSLAYER_ACCEPTOR_H

#include "translayer/channel.h"
#include "translayer/socket.h"

#include <functional>

#include "base/inet_address.h"
#include "translayer/eventloop.h"


namespace sparrow {

// 连接接收器, 向 Server 提供回调作为接口
class Acceptor
{
public:

    using NewConnectionCallback = std::function<void()>;

    Acceptor(EventLoop* loop, const InetAddress& addr, bool reuseport);
    ~Acceptor();

    void SetNewConnectionCallback(NewConnectionCallback& cb) { new_conn_callback_ = cb; }

    void Listen();  // 开始监听

    bool IsListening() const { return listening_; }

private:
    void HandleRead();  // 这个函数不作为接口提供

    EventLoop* loop_;
    Socket accept_socket_;  // 连接套接字
    NewConnectionCallback new_conn_callback_;
    Channel accept_channel_;

    bool listening_{false};
    int idle_fd_{-1}; // 用来当文件描述符数量达到上限时拒绝连接, 见 HandleRead()
};

} // namespace sparrow


#endif  // TRANSLAYER_ACCEPTOR_H