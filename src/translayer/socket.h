#ifndef TRANSLAYER_SOCKET_H
#define TRANSLAYER_SOCKET_H

#include <netinet/tcp.h>  // struct tcp_info

#include "base/inet_address.h"

namespace sparrow {

class Socket
{
private:
    /* data */
public:

    // Create a listen socket
    Socket(sa_family_t family);
    
    // Wrap the connected socket
    Socket(int sockfd) : sockfd_(sockfd) {};

    ~Socket();

    void BindAddress(InetAddress& addr);

    void Listen();

    // On success , return a positive number which is the accepted socket, and peer_addr is assigned.
    // On error, return -1, peer_addr is untouched.
    int Accept(InetAddress* peer_addr);

    int Getfd() const { return sockfd_; }

    void GetTcpInfo (struct tcp_info*) const;

    std::string GetTcpInfoString() const;

    // Below were some socket options/operations

    // Enable/disable TCP_NODELAY option
    void SetTcpNoDelay(bool on);

    void ShutDownWrite();

    // Enable/disable SO_REUSEADDR
    void SetReuseAddr(bool on);

    // Enable/disable SO_REUSEPORT
    void SetReusePort(bool on);

    // Enable/disable SO_KEEPALIVE
    void SetKeepAlive(bool on);

private:
    int sockfd_{-1};  // 默认是无效
};



}  // namespace sparrow

#endif  // TRANSLAYER_SOCKET_H