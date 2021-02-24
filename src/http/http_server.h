#ifndef HTTP_HTTPSERVER_H
#define HTTP_HTTPSERVER_H

#include <functional>

#include "base/inet_address.h"
#include "http/http_response.h"
#include "http/http_request.h"
#include "translayer/eventloop.h"
#include "translayer/tcpserver.h"

namespace sparrow {

class HttpServer
{
public:
    HttpServer(EventLoop *loop,  // 主事件循环
                            InetAddress& listen_addr,  // 监听套接字
                            std::string& name,
                            TcpServer::Option option = TcpServer::Option::kNoReusePort);
    ~HttpServer();

    using BusinessCallBack = std::function<void(const HttpRequest& req, HttpResponse& rep)>;
    
    // 用户定义业务逻辑的唯一接口
    void SetBusinessCallBack(BusinessCallBack& bcb) { business_callback_ = bcb; }

    // 设置线程池数量
    void SetThreadNum(int num) { server_.SetThreadNum(num); }

    void Run();
    
 private:
    void OnConnection();  // tcp 连接回调, 连接建立, 删除, 关闭时都会执行

    void OnMessage();  // tcp 连接收到消息时的回调

    void Response();  // http服务器的响应

    TcpServer server_;
    BusinessCallBack business_callback_;  // 业务逻辑回调
};

}  // namespace sparrow

#endif  // HTTP_HTTPSERVER_H