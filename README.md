
# sparrow
麻雀服务器, 一个简单的 web 服务器, 以学习为主要目的.
仅可在 Linux 下构建, 不跨平台.

诸多类的设计参考了 chenshuo 的 muduo 网络库:  https://github.com/chenshuo/muduo .

# 依赖
pthread
glog
gtest(构建测试才需要, 如果不需要构建单元测试, 将CMake变量设置 BUILD_TESTING 为False即可)

# 构建
cmake -B build . -G Ninja
