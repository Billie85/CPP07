#include "Array.hpp"

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
Array<T>::~Array()
{
	delete[] this->_array;
}

Array &operator=(const Array &original)
{
	//ディープコピーアドレスは違う先の値は同じ
	if (this->_array != NULL)
	{
		delete[] this->_array;
	}
	this->_array = new T[original.len];
	this->len = original.len;//シャドーコピーにする理由はlenは変わる事ないから。lenだけシャドーコピー
	for (size_t i = 0; i < original.len; i++)
	{
		this->_array[i] = original.array[i];//オリジナルの配列から、コピーしたい値の情報を収取する。
	}
	//コピー先　
}

template<typename T>
Array<T>::Array(const Array &original)
{
	this->_array = NULL;
	*this=original;	
}






//c++
/* 
var = new Type()); 
 */

//c
/* 
var = malloc(sizeof(Type)); 
Type_init_defalt(var);
 */


//c++
// var = new Type[5];

//c
/* 
var = malloc(sizeof(Type) * 5);
for (size_t i = 0; i < 5; i++)
{
	Type_init_defalt(var + i);
}
 */
