#include "Array.hpp"
#include "Fixed.hpp"


int main()
{
    std::cout << "==========Test Fixed==========" << std::endl;

    Array<Fixed> Fixedarray(5);
    for (size_t i = 0; i < Fixedarray.size(); i++)
    {
        //最初にキャストしてから、Fixedの引数がintのコンストラクタに渡される。
        //そしたら両辺がFixed型のものになるから、上手くいく。
        Fixedarray[i] = Fixed(static_cast<int>(i));
        std::cout << Fixedarray[i] << std::endl;
    }

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


//公式のmainを使ってしまうとabordしてしまう。
/*  #include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */