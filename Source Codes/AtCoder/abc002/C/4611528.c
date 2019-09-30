#include <stdio.h>
#include <math.h>

int main (void)
{
	/* variables for main process */
	double xa, ya;
	double xb, yb;
	double xc, yc;

	// STEP.01
	// read out the data of coordinates
	scanf ("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);

	// STEP.02
	// calculate & output the area of the triangle
	printf("%lf\n", fabs ( (xb - xa) * (yc -ya) - (xc - xa) * (yb - ya) ) * 5.0e-01 );

	// STEP.TRUE_END
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
  ^