#ifndef __YY_STRING_H__
#define __YY_STRING_H__

#include <string>
#include <cstdio>

namespace yy {

template <typename... Targs>
std::string sprintf(const std::string& format, Targs... args) {
    std::size_t length = std::snprintf(nullptr, 0, format.c_str(), args...);
    char buffer[length + 1];
    std::sprintf(buffer, format.c_str(), args...);
    return std::string(buffer, buffer + length);
}

} // namespace yy

#endif // __YY_STRING_H__
