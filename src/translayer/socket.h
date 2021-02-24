#ifndef TRANSLAYER_SOCKET_H
#define TRANSLAYER_SOCKET_H

namespace sparrow {

class Socket
{
private:
    /* data */
public:
    Socket(int sockfd);
    ~Socket();

    void BindAddress();

    void listen();

private:
    const int sockfd_;
};



}  // namespace sparrow

#endif  // TRANSLAYER_SOCKET_H