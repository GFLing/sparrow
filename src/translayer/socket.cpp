#include <glog/logging.h>

#include "translayer/socket.h"

namespace sparrow {

Socket::Socket(sa_family_t family) {
    int sockfd = ::socket(family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
    if(sockfd < 0) {
        LOG(FATAL) << "Socket::Socket()";
    }
    sockfd_ = sockfd;
}

Socket::~Socket() {
    int ret = ::close(sockfd_);
    if(ret < 0) {
        LOG(ERROR) << "Socket::~Socket()";
    }
}

void Socket::BindAddress(InetAddress& addr) {
    int ret = ::bind(sockfd_, addr.GetSockAddr(), sizeof(struct sockaddr_in6));
    if( ret < 0) {
        LOG(ERROR) << "Socket::BindAddress()";
    }
}

void Socket::Listen() {
    int ret = ::listen(sockfd_, SOMAXCONN);
    if( ret < 0) {
        LOG(ERROR) << "Socket::Listen()";
    }
}

int Socket::Accept(InetAddress* peer_addr) {
    sockaddr_in6 addr{};  // 0初始化
    socklen_t addr_len = sizeof(addr);
    int connfd = ::accept4(sockfd_, reinterpret_cast<sockaddr*>(&addr),
                                    &addr_len, SOCK_CLOEXEC | SOCK_NONBLOCK);
                                    // SOCK_NONBLOCK 表示后续对连接socket 的读写会以非阻塞方式进行 
    if(connfd < 0) {
        
    }
    if(connfd >= 0) {  // 只有成功时才会修改 peer_addr
        peer_addr->SetSockAddr(addr);
    }
    return connfd;
}

void Socket::GetTcpInfo (struct tcp_info*) const {

}

std::string Socket::GetTcpInfoString() const {

}

void Socket::SetTcpNoDelay(bool on) {

}

void Socket::ShutDownWrite() {

}

void Socket::SetReuseAddr(bool on) {

}

void Socket::SetReusePort(bool on) {

}

void Socket::SetKeepAlive(bool on) {

}

}  // namespace sparrow