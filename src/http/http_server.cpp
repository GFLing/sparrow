#include "http/http_server.h"

namespace sparrow {

HttpServer::HttpServer(EventLoop *loop,  // 主事件循环
                            InetAddress& listen_addr,  // 监听套接字
                            std::string& name,
                            TcpServer::Option option = TcpServer::Option::kNoReusePort) 
    : server_(loop, ) {

}
HttpServer::~HttpServer()
{
}


}  // namespace sparrow