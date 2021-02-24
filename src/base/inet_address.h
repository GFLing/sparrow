#ifndef BASE_INET_ADDRESS_H
#define BASE_INET_ADDRESS_H

#include <string>

#include "netinet/in.h"

namespace sparrow {

// wrapper of sockaddr_in
class InetAddress
{
public:

    InetAddress(u_int16_t port, bool loopback = false, bool ipv6 = false);

    InetAddress(std::string ip, uint16_t port, bool ipv6 = false);

    explicit InetAddress(const struct sockaddr_in& addr) : addr_(addr) {}

    explicit InetAddress(const struct sockaddr_in6& addr6) : addr6_(addr6) {}

    ~InetAddress(){};

    // 获得 sockaddr
    const struct sockaddr* GetSockAddr() const { return reinterpret_cast<const struct sockaddr*>(&addr6_) ;}
    // 获得 sa_family_t
    sa_family_t GetFamily() const { return addr6_.sin6_family; }

    // 网络字节序的二进制转换成点分十进制
    std::string GetIP() const;
    
    // 获得端口
    uint16_t GetPort() const;

    // 同时获得IP和端口 x.x.x.x:xxxx
    std::string GetIPAndPort() const;

private:

    // 只会使用到其中一个, 所以使用 union 节省空间
    union 
    {
        struct sockaddr_in addr_;
        struct sockaddr_in6 addr6_;
    };
    
};

} // namespace sparrow

#endif