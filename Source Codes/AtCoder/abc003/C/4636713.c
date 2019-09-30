#include <stdio.h>
#include <stdlib.h>

#define num_videos_max  100

int compare_int (const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main (void)
{
	/* variables for main process */
	double val_rate_max;
	int    val_rate[num_videos_max] = {0};
	size_t num_videos_given, num_videos_watch;

	/* support variables for main process */
	int rtvl_scanf;

	// STEP.01
	// read out the number of videos
	rtvl_scanf = scanf ("%zu %zu", &num_videos_given, &num_videos_watch);

	// STEP.02
	// read out the values of the rate of each video
	for (size_t itr = 0; itr < num_videos_given; itr++) { rtvl_scanf = scanf ("%d", &val_rate[itr]); }

	// STEP.03
	// sort the values of the rate of videos
	// using `qsort` included in <stdlib.h>
	qsort (val_rate, num_videos_given, sizeof(int), compare_int);

	// STEP.04
	// calculate the reachable maximum rate
	val_rate_max = 0.0e+00;
	for (size_t itr = num_videos_given-num_videos_watch; itr < num_videos_given; itr++)
	{
		val_rate_max += (double) val_rate[itr];
		val_rate_max *= 0.5;
	}

	// STEP.05
	// output the result
	printf ("%lf\n", val_rate_max);

	// STEP.TRUE_END
	return 0;
}