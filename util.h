#ifndef __YY_STRING_H__
#define __YY_STRING_H__

#include <cstdio>
#include <map>
#include <string>
#include <vector>

namespace yy {

template <typename... Targs>
std::string sprintf(const std::string& format, Targs... args) {
    std::size_t length = std::snprintf(nullptr, 0, format.c_str(), args...);
    char buffer[length + 1];
    std::sprintf(buffer, format.c_str(), args...);
    return std::string(buffer, buffer + length);
}

template <typename Type>
Type clamp(const Type& v, const Type& lo, const Type& hi) {
    return std::max(lo, std::min(hi, v));
}

template <typename Type>
bool includes(const std::vector<Type>& list, const Type& element) {
    auto itr = std::find(list.begin(), list.end(), element);
    return itr != list.end();
}

template <typename Key, typename Value>
bool includes(const std::map<Key, Value>& dict, const Key& key) {
    auto itr = dict.find(key);
    return itr != dict.end();
}

} // namespace yy

#endif // __YY_STRING_H__
