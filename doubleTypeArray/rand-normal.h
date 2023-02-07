#ifndef RAND_NORMAL
#define RAND_NORMAL

/** get a random number between 0 and 1 */
#include <random>
#include <math.h>
#define UNIT_RAND() (random() / (1.0+RAND_MAX))

double rand_normal(double mean, double dev);

#endif