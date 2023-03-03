#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

template<typename T>
class Array
{
private:
	T *_array;
	size_t len;
public:
	size_t size() const;
	Array();
	Array(unsigned int n);
	Array(const Array<T> &original);

	Array<T> &operator=(const Array<T> &original);
	T &operator[](size_t i);
	~Array();
};

#include "Array.tpp"


#endif