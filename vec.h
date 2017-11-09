#ifndef __VEC_H__
#define __VEC_H__

#include <array>
#include <ostream>
#include <iterator>

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

typedef tvec<float, 3> vec3;
typedef tvec<int, 3> ivec3;

} // namespace yy

#endif // __VEC_H__
