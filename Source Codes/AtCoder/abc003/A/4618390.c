#include <stdio.h>

int calc_salary (int num_tasks)
{
	return 5000 * (num_tasks + 1);
}

int main (void)
{
	/* variables for main process */
	int num_tasks;

	/* support variables for main process */
	int rtvl_scanf;

	// STEP.01
	// read out the target integers
	rtvl_scanf = scanf ("%d", &num_tasks);

	// STEP.02
	// calculate & output the average of salary
	printf("%d\n", calc_salary (num_tasks));

	// STEP.TRUE_END
	return 0;
}