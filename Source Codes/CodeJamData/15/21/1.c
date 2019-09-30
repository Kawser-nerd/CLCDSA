#include <stdio.h>

int sol[1000000];

int reverse (int N)
{
	int rtn = 0;

	while (N > 0)
	{
		rtn = rtn*10 + (N%10);
		N /= 10;
	}

	return rtn;
}

int main (void)
{
	int T, t, i;
	int N, M;

	sol[1] = 1;

	for (i = 1; i <= 1000000; i++)
	{
		N = i + 1;
		M = reverse (i);
		if (sol[N] == 0 || sol[N] > sol[i] + 1) sol[N] = sol[i] + 1;
		if (sol[M] == 0 || sol[M] > sol[i] + 1) sol[M] = sol[i] + 1;
	}

	scanf ("%d", &T);

	for (t = 0; t < T; t++)
	{
		scanf ("%d", &N);

		printf ("Case #%d: %d\n", t + 1, sol[N]);
	}
}
