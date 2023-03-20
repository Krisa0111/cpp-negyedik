
#include <iostream>
#include "Fractional.h"

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
}
