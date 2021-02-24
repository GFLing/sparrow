#include "util/config_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>

namespace sparrow {

namespace {
    void ShowUsageAndExit(const char* name, int exit_code) {
        printf("A tiny reactor web server under Linux.\n");
        printf("Usage: %s [OPTION]\n", name);
        printf("Options:\n");
        printf("  -p, port.\n");
        printf("  -l, listen fd trigger mode, 0 for ET(default), 1 for LT.\n");
        printf("  -c, connection fd trigger mode, 0 for ET(default), 1 for LT.\n");
        printf("  -s, sql connection number.\n");
        printf("  -t, thread number.\n");
        printf("  -a, actor mode, 0 for Reactor(default), 1 for Proactor.\n");
        exit(exit_code);
    }
}

// 默认值
ConfigParser::ConfigParser() {
    this->port_ = 5002;
    this->lisn_trigmode_ = TrigMode::ET;
    this->conn_trigmode_ = TrigMode::ET;
    this->sql_num_ = 8;
    this->thread_num_ = 8;
    this->actor_mode_ = ActorMode::Reactor;
}

ConfigParser::~ConfigParser() {}

void ConfigParser::Parse(int argc, char* argv[]) {
    char opt;
    const char* str = "p:l:c:s:t:a:";
    while((opt = getopt(argc, argv, str)) != -1) {
        if(optarg == nullptr) {
            ShowUsageAndExit(argv[0], 1);
        }
        int res = atoi(optarg);
        switch (opt) {
        case 'p':
            this->port_ = res;
            break;

        case 'l':
            this->lisn_trigmode_ = (res == 0) ? TrigMode::ET : TrigMode::LT;
            break;

        case 'c':
            this->conn_trigmode_ = (res == 0) ? TrigMode::ET : TrigMode::LT;
            break;
            
        case 's':
            this->sql_num_ = res;
            break;

        case 't':
            this->thread_num_ = res;
            break;

        case 'a':
            this->actor_mode_ = (res == 0) ? ActorMode::Reactor : ActorMode::Proactor;
            break;

        default:
            
            break;
        }
    }
}

}  // namespace sparrow
