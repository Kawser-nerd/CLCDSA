#include <stdio.h>
#include <math.h>

double calc_area (double *xa, double *ya, double *xb, double *yb, double *xc, double *yc)
{
	return fabs ( (*xb - *xa) * (*yc -*ya) - (*xc - *xa) * (*yb - *ya) ) * 5.0e-01;
}

int main (void)
{
	/* variables for main process */
	int    rtvl_scanf;
	double xa, ya;
	double xb, yb;
	double xc, yc;

	// STEP.01
	// read out the data of coordinates
	rtvl_scanf = scanf ("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);

	// STEP.02
	// calculate & output the area of the triangle
	printf ("%lf\n", calc_area(&xa, &ya, &xb, &yb, &xc, &yc) );

	// STEP.TRUE_END
	return 0;
}