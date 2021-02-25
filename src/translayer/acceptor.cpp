#include "translayer/acceptor.h"
namespace sparrow {

Acceptor::Acceptor(EventLoop* loop, const InetAddress& addr, bool reuseport)
                     : loop_(loop), 
                     accept_socket_(addr.GetFamily()),
                     accept_channel_()
{

}

Acceptor::~Acceptor()
{
}    

void Acceptor::Listen() {

}

} // namespace sparrow
