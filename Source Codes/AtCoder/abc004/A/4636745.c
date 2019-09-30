#include <stdio.h>

int main (void)
{
	/* variables for main process */
	int N;

	// STEP.01
	// read out the target integer
	int rtvl_scanf = scanf ("%d", &N);

	// STEP.02
	// output the result
	printf ("%d\n", 2*N);

	// STEP.END
	return 0;
}