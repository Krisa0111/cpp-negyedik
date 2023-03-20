
#include <iostream>
#include "Fractional.h"
#include <exception>

int main()
{
    Fractional f(1,2);
    Fractional d(4);

    std::cout << f << std::endl;

    Fractional f1 = f + d;
    const Fractional f2 = f + 4;
    Fractional f3 = 3 + f;
    f3 += f1;
    std::cout << f3;
    try
    {
        Fractional f(7, 0);
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    Fractional f4 = Fractional::ReadLine();
    std::cout << f << std::endl;

    //double d = static_cast<double>(f1);
    if (f1)
    {

    }
    f1 == f2;
}
