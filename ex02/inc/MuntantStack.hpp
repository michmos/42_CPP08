
#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
private:

public:
	// MutantStack();
	// MutantStack(const MutantStack &);
	// MutantStack(MutantStack &&);
	// ~MutantStack();

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

	const_reverse_iterator rcbegin() const {
		return (std::stack<T>::c.rcbegin());
	}

	const_reverse_iterator rcend() const {
		return (std::stack<T>::c.rcend());
	}




};
