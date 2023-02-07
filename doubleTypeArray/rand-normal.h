#ifndef RAND_NORMAL
#define RAND_NORMAL
#include <math.h>
#include "OSCheck.h"

/** get a random number between 0 and 1 */
#define UNIT_RAND() (getOsName()=="Windows") ? (rand() / (1.0+RAND_MAX)) : (random() / (1.0+RAND_MAX))


double rand_normal(double mean, double dev);

#endif