#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626

double sqr(double x) { return x*x; }

double fun(double x, double a)
{
	return 0.5 * (asin(x / a) * a * a + x * sqrt(1 - sqr(x/a)));
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int c = 1; c <= n; c++)
	{
		double res = 0;
		double f, R, t, r, g;
		double block, dim, inrad, sinrad;

		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		block = 2*r + g;
		dim = g - 2*f;
		inrad = R - t - f; 
		sinrad = sqr(inrad);

		if (dim <= 0) res = 0;
		else for (double x = r + f; x < inrad; x += block) for (double y = r + f; y < inrad; y += block)
		{
			double si, ei;

			if (sqr(x) + sqr(y) >= sinrad) continue;
			if (sqr(x + dim) + sqr(y + dim) < sinrad)
			{
				res += sqr(dim);
				continue;
			}

			ei = sqrt(sinrad - sqr(y));
			if (ei > x + dim) ei = x + dim;

			if (sqr(x) + sqr(y + dim) >= sinrad) si = x;
			else
			{
				si = sqrt(sinrad - sqr(y+dim));
				res += (si - x) * dim;
			}
			res += fun(ei, inrad) - fun(si, inrad) - y * (ei - si);
		}
		
		printf("Case #%d: %f\n", c, 1.0 - 4 * res / (PI * R * R));
	}
	return 0;
}
