
#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

class Span {
private:
	std::size_t			capacity_;
	std::vector<int>	numbers_;
	
public:
	Span(unsigned int N);
	Span(const Span& toCopy) noexcept(false);
	Span& operator=(const Span& toAsgn) noexcept(false);
	~Span();

	void 			addNumber(int num) noexcept(false);
	unsigned int	shortestSpan() const; // THROW if not found
	unsigned int	longestSpan() const; // THROW if not found

	template<typename InputIt>
	void	addNumbers(InputIt first, InputIt last) noexcept(false) {
		size_t availableSpace = capacity_ - numbers_.size();
		size_t rangeSize = std::distance(first, last); // TODO: note for iterators - '-' only supported by random access iterators
		if (rangeSize > availableSpace)
			throw std::invalid_argument("addNumbers(): range size exceeds available space");

		numbers_.insert(numbers_.end(), first, last);

	}
};
