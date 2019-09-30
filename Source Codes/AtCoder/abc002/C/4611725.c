#include <stdio.h>
#include <math.h>

typedef struct {
	double cdx;
	double cdy;
} coordinate;


double calc_area (coordinate A, coordinate B, coordinate C)
{
	return fabs ( (B.cdx - A.cdx) * (C.cdy -A.cdy) - (C.cdx - A.cdx) * (B.cdy -A.cdy) ) * 5.0e-01;
}

int main (void)
{
	/* variables for main process */
	int        rtvl_scanf;
	coordinate pnt_A, pnt_B, pnt_C;

	// STEP.01
	// read out the data of coordinates
	rtvl_scanf = scanf ("%lf %lf %lf %lf %lf %lf", &pnt_A.cdx, &pnt_A.cdy, &pnt_B.cdx, &pnt_B.cdy, &pnt_C.cdx, &pnt_C.cdy);

	// STEP.02
	// calculate & output the area of the triangle
	printf ("%lf\n", calc_area(pnt_A, pnt_B, pnt_C) );

	// STEP.TRUE_END
	return 0;
}