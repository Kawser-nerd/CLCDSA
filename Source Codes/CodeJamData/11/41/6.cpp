#include <stdio.h>

int w[101];
double ans;
int l, v, r, n;
double t;

int main ()
{
	int tt, ct = 0;

	for (scanf ("%d", &tt); tt > 0; tt --)
	{
		scanf ("%d%d%d%lf%d", &l, &v, &r, &t, &n);
		for (int i = 0; i <= 100; i ++)
			w[i] = i == 0? l : 0;
		for (int i = 0; i < n; i ++)
		{
			int a, b, c;
			
			scanf ("%d%d%d", &a, &b, &c);
			w[c] += b - a;
			w[0] -= b - a;
		}

		double ans = 0;

		for (int i = 0; i <= 100; i ++)
			if (w[i] > 0)
			{
				if (w[i] / (double)(i + r) <= t + 1e-10)
				{
					t -= w[i] / (double)(i + r);
					ans += w[i] / (double)(i + r);
				}
				else
				{
					ans += t + (w[i] - t * (i + r)) / (double)(i + v);
					t = 0;
				}
			}

		printf ("Case #%d: %.6lf\n", ++ ct, ans);
	}

	return 0;
}
