#include "Array.hpp"

//=======constructor and destructor=======
template<typename T>
Array<T>::Array()
{
	this->_array = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->len = n;
	this->_array = new T[n];
}

template<typename T>
Array<T>::Array(const Array &original)
{
	this->_array = NULL;
	*this=original;	
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

//======function=======
template<typename T>
size_t Array<T>::size() const
{
	return(this->len);
}

//======operator=========
template<typename T>
Array<T> &Array<T>::operator=(const Array &original)
{
	//自己代入を避ける。
	if (this != &original)
	{
		delete[] this->_array;
		this->_array = new T[original.len];
		this->len = original.len;
		for (size_t i = 0; i < original.len; i++)
		{
			this->_array[i] = original._array[i];
		}
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= this->len)
		throw std::out_of_range("Index out of range");
	return(this->_array[i]);
}
