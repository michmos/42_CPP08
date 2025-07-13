

#include <deque>
#include <limits>
#define BOLD "\033[1m"
#define YELLOW	"\033[33;1m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"


#include "../inc/Span.hpp"
#include <iostream>
#include <sys/time.h>

#include <list>

template<typename T>
void	test(const T& initContainer, size_t N) {
	Span	sp(N);
	try {
		sp.addNumbers(initContainer.begin(), initContainer.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	std::srand(tv.tv_usec);

	printf(BOLD YELLOW "\n\nSubject example: \n" RESET);
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	printf(BOLD YELLOW "\n\naddNumbers() list: \n" RESET);
	{
		std::list<int> li = {
			-23, -40, -56, -123, -56
		};
		test(li, li.size());
	}
	printf(BOLD YELLOW "\n\nshortest span between adjacent elements: \n" RESET);
	printf(BOLD YELLOW "longest span between 1. and last element: \n" RESET);
	{
		std::list<int> li = {
			0, 5, 5, 6, 100
		};
		test(li, li.size());
	}
	printf(BOLD YELLOW "\n\nshortest span between 1. and last element: \n" RESET);
	printf(BOLD YELLOW "longest span between adjacent elements: \n" RESET);
	{
		std::list<int> li = {
			10, 0, 100, 6, 10
		};
		test(li, li.size());
	}
	printf(BOLD YELLOW "\n\nGiant container: \n" RESET);
	{
		std::deque<int> deq;
		for (int i = 0; i < 10000; ++i) {
			deq.push_back(rand());
		}
		deq.push_front(std::numeric_limits<int>::min());
		deq.push_back(std::numeric_limits<int>::min());
		deq.push_back(std::numeric_limits<int>::max());
		std::cout << "Size: "<< deq.size() << std::endl;
		test(deq, deq.size());
	}
	return 0;
}
