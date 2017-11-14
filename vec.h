#ifndef __VEC_H__
#define __VEC_H__

#include <array>
#include <ostream>
#include <iterator>
#include <algorithm>

namespace yy {

#define TVEC_ACCESSOR(method, index) \
    const Type& method() const { return _values[index]; } \
    Type& method() { return _values[index]; }

/**
 * A simple vector class similar to GLSL vec.
 */
template <typename Type, int Size>
class tvec {
public:
    tvec() = default;
    template <typename... Targs>
    tvec(Targs... values) : _values{values...} {}
    tvec(std::array<Type, Size> values) : _values(values) {}
    tvec(const std::vector<Type>& values) {
        std::copy_n(values.begin(), Size, _values.begin());
    }
    tvec(std::vector<Type>&& values) {
        std::copy_n(
                std::make_move_iterator(values.begin()), Size, _values.begin());
    }

public:
    operator const std::array<Type, Size>&() const { return _values; }
    operator std::vector<Type>() const {
        std::vector<Type> output(Size);
        std::copy(_values.begin(), _values.end(), output.begin());
        return output;
    }

public:
    const Type& operator[](std::size_t idx) const { return _values[idx]; }
    Type& operator[](std::size_t idx) { return _values[idx]; }
    TVEC_ACCESSOR(x, 0);
    TVEC_ACCESSOR(y, 1);
    TVEC_ACCESSOR(z, 2);
    TVEC_ACCESSOR(w, 3);

private:
    std::array<Type, Size> _values;
};

/**
 * Shortcuts for the templated vector classes.
 */
typedef tvec<float, 3> vec3;
typedef tvec<int, 3> ivec3;

/**
 * The output stream operator for easy printing of the vector classes.
 */
template <typename Type, int Size>
std::ostream& operator<<(std::ostream& os, const tvec<Type, Size>& v) {
    os << v[0];
    for (int i = 1; i < Size; ++i) {
        os << " " << v[i];
    }
    return os;
}

/**
 * The operators
 */
template <typename Type, int Size, typename Func>
tvec<Type, Size> perElementOperation(
        const tvec<Type, Size>& a, const tvec<Type, Size>& b, Func func) {
    tvec<Type, Size> c;
    for (int i = 0; i < Size; ++i) {
        c[i] = func(a[i], b[i]);
    }
    return c;
}

template <typename Type, int Size>
tvec<Type, Size> operator/(
        const tvec<Type, Size>& a, const tvec<Type, Size>& b) {
    return perElementOperation(
            a, b, [](const Type& aa, const Type& bb) { return aa / bb; });
}

template <typename Type, int Size>
tvec<Type, Size> operator*(
        const tvec<Type, Size>& a, const tvec<Type, Size>& b) {
    return perElementOperation(
            a, b, [](const Type& aa, const Type& bb) { return aa * bb; });
}

} // namespace yy

#endif // __VEC_H__
