#include "iter.hpp"

template<typename T>
void print(T &element)
{
	std::cout << element << std::endl;
	element++;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 4, print);
	std::cout << "------------------" << std::endl;
	iter(intArray, 4, print);
	std::cout << "------------------" << std::endl;
	double doubleArray[] = {3.14, 3.15, 3.16, 3.17};
	iter(doubleArray, 4, print);
}