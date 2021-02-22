#ifndef UTIL_CONFIGPARSER_H
#define UTIL_CONFIGPARSER_H

#include <stdint.h>

namespace sparrow {

enum class TrigMode : uint8_t {
    ET = 0,
    LT = 1
};

enum class ActorMode : uint8_t {
    Reactor = 0,
    Proactor = 1
};

class ConfigParser
{
public:
    ConfigParser();
    ~ConfigParser();

    void Parse(int argc, char* argv[]);  // 解析命令行

public:
    int port_;  // 端口
    TrigMode lisn_trigmode_;  // 监听套接字触发方式
    TrigMode conn_trigmode_;  // 连接套接字触发方式
    int sql_num_;  // 数据库连接池数量
    int thread_num_;  // 线程池内线程数量
    ActorMode actor_mode_;  // 响应方式 reator or proactor
};

}  // namespace sparrow

#endif