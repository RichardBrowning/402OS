#ifndef RAND_NORMAL
#define RAND_NORMAL

/** get a random number between 0 and 1 */
//#define UNIT_RAND() (random() / (1.0+RAND_MAX))
#define UNIT_RAND_WIN() (rand() / (1.0+RAND_MAX))

#include <math.h>

double rand_normal(double mean, double dev);

#endif