#include <iostream>

#include "util/config_parser.h"
#include "translayer/tcpserver.h"

int main(int argc, char *argv[]) {
    sparrow::ConfigParser configparser;
    configparser.Parse(argc, argv);

    return 0;

}  // namespace sparrow