#ifndef RAND_NORMAL
#define RAND_NORMAL
//#define UNIT_RAND()    (rand() / (1.0+RAND_MAX))

/** get a random number between 0 and 1 */
#define UNIT_RAND()    (random() / (1.0+RAND_MAX))

#include <math.h>

double rand_normal(double mean, double dev);

#endif