#include "Array.hpp"

int main()
{
	std::cout << "==========Test Int==========" << std::endl;

	Array<int> intarray(5);
	for (size_t i = 0; i < intarray.size(); i++)
	{
		intarray[i] = i;
		std::cout << intarray[i] << std::endl;
	}

	std::cout << "==========Test char==========" << std::endl;
	Array<char> chararray(5);
	for (size_t i = 0; i < chararray.size(); i++)
	{
		chararray[i] = 'a' + static_cast<char>(i);
		std::cout << chararray[i] << std::endl;
	}

	std::cout << "==========Test double==========" << std::endl;
	Array<double> doublearray(5);
	for (size_t i = 0; i < doublearray.size(); i++)
	{
		doublearray[i] = i;
		std::cout << doublearray[i] << std::endl;
	}

	std::cout << "==========Test float==========" << std::endl;
	Array<float> floatarray(5);
	for (size_t i = 0; i < floatarray.size(); i++)
	{
		floatarray[i] = i;
		std::cout << floatarray[i] << std::endl;
	}
}

