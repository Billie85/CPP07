#include "iter.hpp"

template<typename T>
void print(T &element)
{
	std::cout << element << std::endl;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5, 6};
	iter(intArray, 6, print);

	double doubleArray[] = {3.14, 3.15, 3.16, 3.17};
	iter(doubleArray, 4, print);
}