#include "../inc/MuntantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>

#define BOLD "\033[1m"
#define YELLOW	"\033[33;1m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void subjectTestsWithList() {
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << *std::prev(lst.end()) << std::endl;
	lst.erase(std::prev(lst.end()));
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void subjectTests() {
	MutantStack<int>
	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main()
{
	printf(BOLD YELLOW "\n\nSubject Tests: \n" RESET);
	subjectTests();
	printf(BOLD YELLOW "\n\nSubject Tests with std::list: \n" RESET);
	subjectTestsWithList();
	printf(BOLD YELLOW "\n\nCopy constructor: \n" RESET);
	MutantStack<int> words;
	for (int i = 0; i < 10; ++i) {
		words.push(i);
	}
	MutantStack<int> copy(words);
	printf(BOLD YELLOW "Forward Iterator: \n" RESET);
	for (auto it = copy.begin(); it != copy.end(); ++it) {
		std::cout << *it << " ";
	}
	printf(BOLD YELLOW "\n\nReverse iterator: \n" RESET);
	for (auto it = copy.rbegin(); it != copy.rend(); ++it) {
		std::cout << *it << " ";
	}
	printf(BOLD YELLOW "\n\nConst Forward Iterator: \n" RESET);
	for (auto it = copy.cbegin(); it != copy.cend(); ++it) {
		std::cout << *it << " ";
	}
	printf(BOLD YELLOW "\n\nConsr Reverse iterator: \n" RESET);
	for (auto it = copy.crbegin(); it != copy.crend(); ++it) {
		std::cout << *it << " ";
	}
	printf(BOLD YELLOW "\n\nChanging values through forward iterator: \n" RESET);
	std::for_each(copy.begin(), copy.end(), [](int &x) { x += 10; });
	for (auto it = copy.cbegin(); it != copy.cend(); ++it) {
		std::cout << *it << " ";
	}
	printf(BOLD YELLOW "\n\nArithmetic operation: .begin() + 5: \n" RESET);
	std::cout << *(copy.begin() + 5) << std::endl;

	printf(BOLD YELLOW "\n\nstd::next(container.begin(), 5): \n" RESET);
	std::cout << *(std::next(copy.begin(), 5)) << std::endl;
	// printf(BOLD YELLOW "\n\nChanging values through const forward iterator: \n" RESET);
	// std::for_each(copy.cbegin(), copy.cend(), [](int &x) { x += 10; });
	// for (auto it = copy.cbegin(); it != copy.cend(); ++it) {
	// 	std::cout << *it << " ";
	// }

	return 0;
}
