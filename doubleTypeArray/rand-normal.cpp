#include "rand-normal.h"

double rand_normal(double mean, double dev)
{
	static int saved = 0;
	static double y;
	double px, py, d2, x, u;

	if (saved) {
		saved = 0;
		return y * dev + mean;
	}

	do {
		px = UNIT_RAND() * 2.0 - 1.0; /* random b/w [-1,1) */
		py = UNIT_RAND() * 2.0 - 1.0; 
		d2 = px * px + py * py;
	} while (d2 == 0.0 || d2 > 1.0); // find a random point in a unit circle
	
	u = sqrt(-2.0 * log(d2) / d2);
	x = px * u;
	y = py * u;			// save the other value for the next call
	saved = 1;
	return x * dev + mean;
}