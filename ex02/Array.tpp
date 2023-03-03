#include "Array.hpp"

//=======constructor and destructor=======
//コンストラクタは3種類ある。

template<typename T>
Array<T>::Array()
{
	//std::cout << "default constructor called" << std::endl;
	this->_array = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	//std::cout << "unsigned int constructor called" << std::endl;
	this->len = n;
	this->_array = new T[n];
}

template<typename T>
Array<T>::Array(const Array &original)
{
	//std::cout << "copy constructor called" << std::endl;
	this->_array = NULL;
	*this=original;	
}

template<typename T>
Array<T>::~Array()
{
	//std::cout << "Destroyed" << std::endl;
	delete[] this->_array;
}

//======function=======
template<typename T>
size_t Array<T>::size() const
{
	//std::cout << "Size function called" << std::endl;
	return(this->len);
}

//======operator=========
template<typename T>
Array<T> &Array<T>::operator=(const Array &original)
{
	//std::cout << "operator= called" << std::endl;
	//ディープコピーアドレスは違う,先の値は同じ
	if (this->_array != NULL)
	{
		delete[] this->_array;
	}
	this->_array = new T[original.len];
	this->len = original.len;//シャドーコピーにする理由はlenは変わる事ないから。lenだけシャドーコピー
	for (size_t i = 0; i < original.len; i++)
	{
		this->_array[i] = original._array[i];
		//オリジナルの配列から、コピーしたい値の情報を収取する。
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t i)
{
	//std::cout << "operator[] called" << std::endl;
	if (i > this->len)
		throw (std::exception());
	return(this->_array[i]);
}
