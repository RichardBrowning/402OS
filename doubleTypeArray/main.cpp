#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "rand-normal.h"

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        std::cout << rand_normal(0, 1) << std::endl;
    }
    return 0;
}