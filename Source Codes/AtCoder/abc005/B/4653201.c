#include <stdio.h>
#include <limits.h>

#define num_takoyaki_max 100

int main (void)
{
	/* variables for main process */
	char num_takoyaki;
	char seconds_buf, seconds_min;

	/* support variables for main process */
	int rtvl_scanf;

	// STEP.01
	// read out the number of takoyaki
	rtvl_scanf = scanf ("%d", &num_takoyaki);

	// STEP.02
	//   read out the values of second from made
	// & check whether it is minimum
	seconds_min = CHAR_MAX;

	for (char itr = 0; itr < num_takoyaki; itr++)
	{
		rtvl_scanf = scanf ("%d", &seconds_buf);

		if (seconds_buf < seconds_min) { seconds_min = seconds_buf; }
	}

	// STEP.03
	// output the minimum value
	printf ("%d\n", seconds_min);

	// STEP.END
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:22: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘char *’ [-Wformat=]
  rtvl_scanf = scanf ("%d", &num_takoyaki);
                      ^
./Main.c:26:23: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘char *’ [-Wformat=]
   rtvl_scanf = scanf ("%d", &seconds_buf);
                       ^