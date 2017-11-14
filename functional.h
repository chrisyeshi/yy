#ifndef __YY_FUNCTIONAL_H__
#define __YY_FUNCTIONAL_H__

#include <functional>

namespace yy {
namespace fp {

template <typename Type, typename Transform>
auto map(const std::vector<Type>& input, Transform transform)
		-> std::vector<decltype(transform(input[0]))> {
	std::vector<Type> output(input.size());
	for (unsigned int i = 0; i < input.size(); ++i) {
		output[i] = transform(input[i]);
	}
	return output;
}

template <typename Type, typename Evaluate>
std::vector<Type> filter(const std::vector<Type>& input, Evaluate evaluate) {
	std::vector<Type> output;
	for (const auto& entry : input) {
		if (evaluate(entry)) {
			output.push_back(entry);
		}
	}
	return output;
}

template <typename Type>
std::vector<Type> sort(const std::vector<Type>& input) {
	std::vector<Type> output = input;
	std::sort(output.begin(), output.end());
	return output;
}

} // namespace fp
} // namespace yy

#endif // __YY_FUNCTIONAL_H__