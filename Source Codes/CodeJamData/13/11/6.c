#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int is_ok(long long r, long long v, long long n)
{
	return n <= v / (2 * r + 2 * n - 1);
}

void do_test(int t)
{
	long long r, v;
	long long approx_n;
	long long upper, lower;

	scanf("%lld%lld", &r, &v);

	approx_n = 1 + sqrt(t/2); /* First approximation */

	fprintf(stderr, "%d: Approximation = %lld\n", t + 1, approx_n);

	if (is_ok(r, v, approx_n))
	{
		lower = approx_n;
		upper = lower * 2;

		while (is_ok(r, v, upper))
		{
			long long old_upper = upper;
			upper *= 2;
			lower = old_upper;
		}
	}
	else
	{
		upper = approx_n;
		lower = upper / 2;

		while (!is_ok(r, v, lower))
		{
			long long old_lower = lower;
			lower /= 2;
			upper = old_lower;
		}
	}

	/* Now have a range */
	fprintf(stderr, "%d: Range = { %lld, %lld }\n", t+1, lower, upper);

	while (upper - lower > 1)
	{
		long long test = lower + (upper - lower) / 2;

		if (is_ok(r, v, test))
			lower = test;
		else
			upper = test;
	}

	/* Now lower should be the answer */

	printf("Case #%d: %lld\n", t + 1, lower);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
