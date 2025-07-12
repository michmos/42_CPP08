
#pragma once
#include <algorithm>

template<typename T>typename T::iterator	easyfind(T& container, int toFind) {
	auto it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end()) {
		throw std::exception();
	}
	return (it);
}
