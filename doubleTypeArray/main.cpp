#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "rand-normal.h"
#include "OSCheck.h"

int main()
{
    std::cout << getOsName() << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << rand_normal(0, 1) << std::endl;
    }
    return 0;
}