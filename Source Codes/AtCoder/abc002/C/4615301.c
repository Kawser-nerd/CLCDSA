#include <stdio.h>
#include <math.h>

typedef struct {
	double cdx;
	double cdy;
} coordinate;

coordinate subtract_vector (coordinate *point_start, coordinate *point_end)
{
	// return value of this function
	coordinate retval;

	// calculate the return value
	retval.cdx = point_start->cdx - point_end->cdx;
	retval.cdy = point_start->cdy - point_end->cdy;

	// declare the return value
	return retval;
}

double calc_area (coordinate *A, coordinate *B, coordinate *C)
{
	// variables for this function
	coordinate AB, AC;

	// STEP.01 | calculate the vectors
	AB = subtract_vector (A, B);
	AC = subtract_vector (A, C);

	return fabs ( AB.cdx * AC.cdy - AC.cdx * AB.cdy ) * 5.0e-01;
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
	printf ("%lf\n", calc_area (&pnt_A, &pnt_B, &pnt_C) );

	// STEP.TRUE_END
	return 0;
}