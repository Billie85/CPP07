#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class Array
{
private:
	T _array[];
	size_t len;
	// Type Var[]; // Type *Var;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &original);
	Array &operator=(const Array &original);
	Array &operator[](const Array &original);
	~Array();
};

#endif