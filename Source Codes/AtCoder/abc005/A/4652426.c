#include <stdio.h>

int main (void)
{
	/* variables for main process */
	int x, y;

	// STEP.01
	// read out the data
	int rtvl_scanf = scanf ("%d %d", &x, &y);

	// STEP.02
	// compute & output the result
	printf ("%d\n", y / x);

	// STEP.END
	return 0;
}