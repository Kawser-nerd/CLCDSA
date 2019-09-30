#include <stdio.h>

static inline
double min(double a, double b)
{
	return a < b ? a : b;
}

int main(int argc, const char* argv[])
{
	int T, t;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		double C, F, X;
		int j, n;
		double best, test;

		scanf("%lf %lf %lf", &C, &F, &X);
		n = (int)(X / C - 2.0 / F) - 1 - 1;
		if (n < 0)
			n = 0;

		best = X / 2.0;

		test = 0.0;
		for (j = 0; j < n; j++)
			test += (1.0 / (2.0 + j * F));

		best = min(best, C * test + X / (2.0 + n * F));
		test += (1.0 / (2.0 + n * F)); n++;
		best = min(best, C * test + X / (2.0 + n * F));
		test += (1.0 / (2.0 + n * F)); n++;
		best = min(best, C * test + X / (2.0 + n * F));
		printf("Case #%d: %.7f\n", t, best);
	}
    return 0;
}
