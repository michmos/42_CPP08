
#include "../inc/Span.hpp"
#include <algorithm>
#include <iterator>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int N) : capacity_(N) {
	numbers_.reserve(N);
}

Span::Span(const Span& toCopy) {
	*this = toCopy;
}

Span& Span::operator=(const Span& toAsgn) {
	if (this != &toAsgn) {
		capacity_ = toAsgn.capacity_;
		numbers_ = toAsgn.numbers_;
	}
	return (*this);
}

Span::~Span() {
}

void	Span::addNumber(int num) noexcept(false) {
	if (numbers_.size() >= capacity_) {
		throw std::logic_error("Capacity reached. Cannot add further numbers.");
	}

	numbers_.push_back(num);
}

unsigned int	Span::longestSpan() const {
	if (numbers_.size() < 2) {
		throw std::logic_error("Cannot find span: less than 2 elements available");
	}
	std::vector<int> copy(numbers_);
	std::sort(copy.begin(), copy.end());
	return (*std::prev(copy.end()) - *copy.begin());
}

unsigned int	Span::shortestSpan() const {
	if (numbers_.size() < 2) {
		throw std::logic_error("Cannot find span: less than 2 elements available");
	}

	std::vector<int> copy(numbers_);
	std::sort(copy.begin(), copy.end());
	unsigned int lastElement = *copy.begin();
	unsigned int shortestSpan = std::numeric_limits<int>::max();
	std::for_each(std::next(copy.begin()), copy.end(), [&lastElement, &shortestSpan](int currentElement) {
		unsigned int currentSpan = currentElement - lastElement;
		if (currentSpan < shortestSpan) {
			shortestSpan = currentSpan;
		}
		lastElement = currentElement;
	} );
	return (shortestSpan);
}

