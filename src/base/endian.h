#include <stdint.h>
#include <endian.h>

namespace sparrow {

// 网络字节序转换
inline uint16_t HostToNet(uint16_t host16) {
    return htobe16(host16);
}

inline uint32_t HostToNet(uint32_t host32) {
    return htobe32(host32);
}

inline uint64_t HostToNet(uint64_t host64) {
    return htobe64(host64);
}

inline uint16_t NetToHost(uint16_t net16) {
    return be16toh(net16);
}

inline uint32_t NetToHost(uint32_t net32) {
    return be32toh(net32);
}

inline uint64_t NetToHost(uint64_t net64) {
    return be64toh(net64);
}

} // namespace sparrow
