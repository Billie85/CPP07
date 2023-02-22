#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


/* • The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be call on every element of the array.
1つ目のパラメータは、配列の先頭要素のアドレスを示します。
2つ目のパラメータは、配列の要素数を示します。
3つ目のパラメータは、配列の各要素に適用される関数です。この関数は、配列の各要素に対して呼び出されます。 */

template<typename T>
void iter(T *array, size_t len, void (*func) (T &))
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
	
}

#endif