#include "base/inet_address.h"

#include <string.h>  // memset
#include <arpa/inet.h>  // inet_pton

#include "base/endian.h"

namespace sparrow {

InetAddress::InetAddress(u_int16_t port, bool loopback, bool ipv6) {
    if(ipv6) {
        memset(&addr6_, 0, sizeof addr6_);
        addr6_.sin6_family = AF_INET6;
        addr6_.sin6_addr = loopback ? in6addr_loopback : in6addr_any;
        addr6_.sin6_port = HostToNet(port);
    }
    else {
        memset(&addr_, 0, sizeof addr_);
        addr_.sin_family = AF_INET;
        addr_.sin_addr.s_addr = HostToNet(loopback ? INADDR_LOOPBACK : INADDR_ANY);
        addr_.sin_port = HostToNet(port);
    }
}

InetAddress::InetAddress(std::string ip, uint16_t port, bool ipv6) {
    if(ipv6) {
        memset(&addr6_, 0, sizeof addr6_);
        addr6_.sin6_family = AF_INET6;
        ::inet_pton(AF_INET6, ip.c_str(), &addr6_.sin6_addr);
        addr6_.sin6_port = HostToNet(port);
    }
    else {
        memset(&addr_, 0, sizeof addr_);
        addr_.sin_family = AF_INET;
        ::inet_pton(AF_INET, ip.c_str(), &addr_.sin_addr);
        addr_.sin_port = HostToNet(port);
    }
}

// 网络字节序的二进制转换成点分十进制
std::string InetAddress::GetIP() const {
    char buf[47] = "";  // unp p71, 介绍了这个缓冲区至少为多大
    if(addr_.sin_family == AF_INET) {
        ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    }
    else {
        ::inet_ntop(AF_INET6, &addr6_.sin6_addr, buf, sizeof buf);
    }
    return buf;
}
    
// 获得端口
uint16_t InetAddress::GetPort() const {
    return NetToHost(addr_.sin_port);
}

// 同时获得IP和端口 x.x.x.x:xxxx
std::string InetAddress::GetIPAndPort() const {
    std::string res = GetIP() + ':' + std::to_string(GetPort());
    return res;
}

} // namespace sparrow
