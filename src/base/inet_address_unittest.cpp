#include <glog/logging.h>
#include <gtest/gtest.h>

#include "base/inet_address.h"

namespace sparrow {
    TEST(InetAddressTest, TestConstruct) {
        InetAddress ia0{5001};
        ASSERT_EQ(ia0.GetIP(), std::string("0.0.0.0"));
        ASSERT_EQ(ia0.GetIPAndPort(), std::string("0.0.0.0:5001"));
        ASSERT_EQ(ia0.GetPort(), 5001);

        InetAddress ia1{8888, true};
        ASSERT_EQ(ia1.GetIP(), std::string("127.0.0.1"));
        ASSERT_EQ(ia1.GetIPAndPort(), std::string("127.0.0.1:8888"));
        ASSERT_EQ(ia1.GetPort(), 8888);

        InetAddress ia2{"1.2.3.4", 1234};
        ASSERT_EQ(ia2.GetIP(), std::string("1.2.3.4"));
        ASSERT_EQ(ia2.GetIPAndPort(), std::string("1.2.3.4:1234"));
        ASSERT_EQ(ia2.GetPort(), 1234);
    }
} // namespace sparrow
