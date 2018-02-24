#ifndef YY_SET_H
#define YY_SET_H

#include <vector>
#include "util.h"

namespace yy {
namespace set {

template <typename Type>
std::vector<Type>& extend(
        std::vector<Type>& recvSet, const std::vector<Type>& mergingSet) {
    for (const auto& element : mergingSet) {
        if (!includes(recvSet, element)) {
            recvSet.push_back(element);
        }
    }
    return recvSet;
}

template <typename Type>
std::vector<Type> get_union(std::vector<Type> a, const std::vector<Type>& b) {
    std::vector<Type> result = a;
    return extend(result, b);
}

template <typename Type>
std::vector<Type> intersect(
        const std::vector<Type>& a, const std::vector<Type>& b) {
    std::vector<Type> result;
    for (const auto& element : a) {
        if (includes(b, element)) {
            result.push_back(element);
        }
    }
    return result;
}

} // namespace set
} // namespace yy

#endif // YY_SET_H
