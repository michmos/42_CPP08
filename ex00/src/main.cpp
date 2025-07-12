
#define BOLD "\033[1m"
#define YELLOW	"\033[33;1m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>

template<typename Container>void test(Container &container, int toFind) {
	for (auto it : container) {
		if (it == toFind) {
			std::cout << BOLD GREEN << it << " " << RESET;
		} else {
			std::cout << it << " ";
		}
	}

	try {
		auto it = easyfind(container, toFind);
		std::cout << BOLD GREEN << "\nFound: " << *it << RESET << std::endl;
	} catch (...) {
		std::cout << BOLD RED << "\nNothing found" << RESET << std::endl;
	}
	std::cout << std::endl;
}

int main(void) {
	printf(BOLD YELLOW "\n\nVector: \n" RESET);
	std::vector<int> vec = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	test(vec, 0);
	test(vec, 9);
	test(vec, 10);

	printf(BOLD YELLOW "\n\nList: \n" RESET);
	std::list<int> lis = {
	1289038, -234, 909, 122340, -809809324, 123
	};
	test(lis, 1289038);
	test(lis, -809809324);
	test(lis, 10);

	printf(BOLD YELLOW "\n\nDeq: \n" RESET);
	std::deque<int> deq = {
		-123, 235, 98, 13048, 8098, 1231123
	};
	test(deq, 98);
	test(deq, 1231123);
	test(deq, 10);

	printf(BOLD YELLOW "\n\nset: \n" RESET);
	std::set<int> se = {
		-128, 230498108, 182309, -3452, 123, 298, 123
	};
	test(se, 230498108);
	test(se, -3452);
	test(se, -10000);


	return (0);
}
