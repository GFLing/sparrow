
# sparrow
麻雀服务器, 一个简单的 web 服务器.
仅可在 Linux 下构建, 不跨平台.

本项目以学习练手为目的, 诸多类的设计参考了 chenshuo 的 muduo 网络库:  https://github.com/chenshuo/muduo .

# 依赖
pthread

glog

gtest(构建测试才需要, 如果不需要构建单元测试, 将CMake变量设置 BUILD_TESTING 为False即可)

Linux内核版本 >= 2.6.28 (如果太旧, 会有一些系统调用支持不了, 如accept4())

# 构建
cmake -B build . -G Ninja

# 注意
在测试并发能力之前, 需要先增加进程打开的文件描述符数量来增加性能.


# 小记

监听是一个 eventloop, 其他的线程监听连接套接字也是 eventloop, 那监听到新连接时, 如何将新连接传给别的 eventloop 处理呢?

在创建 acceptor 之后, 进入主进程事件循环, 如果有新连接建立, 我们就会从线程池里拿一个新的 eventloop, 当然这个 loop 是别的线程的loop,
然后往这个loop里添加一个 pending 函数, 等到那个loop被唤醒的时候, 就会执行这个函数, 
这个函数一般是 将新建立连接的channel 添加到那个 eventloop里(channel->update()), 供它epoll_wait.