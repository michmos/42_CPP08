
#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
private:

public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack<T> &toCopy) : std::stack<T>() {
		*this = toCopy;
	};
	MutantStack<T>& operator=(const MutantStack<T> &toAsgn) {
		if (this != &toAsgn) {
			std::stack<T>::operator=(toAsgn);
		}
		return (*this);
	}
	~MutantStack() {}

	// iterators
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	iterator begin() {
		return (std::stack<T>::c.begin());
	}

	iterator end() {
		return (std::stack<T>::c.end());
	}

	const_iterator cbegin() const {
		return (std::stack<T>::c.cbegin());
	}

	const_iterator cend() const {
		return (std::stack<T>::c.cend());
	}

	reverse_iterator rbegin() {
		return (std::stack<T>::c.rbegin());
	}

	reverse_iterator rend() {
		return (std::stack<T>::c.rend());
	}

	const_reverse_iterator crbegin() const {
		return (std::stack<T>::c.crbegin());
	}

	const_reverse_iterator crend() const {
		return (std::stack<T>::c.crend());
	}




};
