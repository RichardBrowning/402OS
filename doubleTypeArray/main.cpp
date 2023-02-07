#include <iostream>
#include <math.h>
#include <time.h>
#include "LinkedListNode.h"
#include "DoubleTypeArray.h"
#include "rand-normal.h"


#define ARRAY_SIZE 30

int main()
{
    srand(time(NULL));
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << rand_normal(0, 1) << std::endl;
    // }

    /** init array*/
    DoubleTypeArray* DTArray = new DoubleTypeArray(ARRAY_SIZE);
    DTArray->print();
    return 0;
}