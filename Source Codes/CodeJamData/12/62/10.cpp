#include <stdio.h>
#include <algorithm>

using namespace std;

double data[1000000];
int dp, k;
double prodl[1000001], prodr[1000001];
double suml[1000001], sumr[1000001];

int main ()
{
	int t, ct = 0;

	for (scanf ("%d", &t); t > 0; t --)
	{
		{
			int n;

			scanf ("%d%d", &n, &k);
			dp = 0;
			for (int i = 0; i < n; i ++)
			{
				int a, b, c;

				scanf ("%d/%d%d", &a, &b, &c);
				for (int j = 0; j < c; j ++)
					data[dp ++] = a / (double) b;
			}

			sort(data, data + dp);
		}

		prodl[0] = 1.0;
		for (int i = 0; i < dp; i ++)
			prodl[i + 1] = prodl[i] * (1 - data[i]);
		prodr[dp] = 1.0;
		for (int i = dp - 1; i >= 0; i --)
			prodr[i] = prodr[i + 1] * data[i];

		suml[0] = 1;
		for (int i = 0; i < dp; i ++)
			suml[i + 1] = suml[i] * data[i] + prodl[i + 1];
		sumr[dp] = 1;
		for (int i = dp - 1; i >= 0; i --)
			sumr[i] = sumr[i + 1] * (1 - data[i]) + prodr[i];

//		for (int i = 0; i <= dp; i ++)
//			printf ("i = %d, prodl prodr suml sumr = %lf %lf %lf %lf\n", i, prodl[i], prodr[i], suml[i], sumr[i]);

		double ans = 1.0;

		for (int i = 0; i <= k; i ++)
		{
			double cur = suml[i] * prodr[dp - (k - i)] +
				(sumr[dp - (k - i)] - prodr[dp - (k - i)]) * prodl[i];
//			printf ("i = %d, cur = %lf*%lf+%lf*%lf=%lf\n", i, suml[i], prodr[dp - (k - i)],
//				(sumr[dp - (k - i)] - prodr[dp - (k - i)]), prodl[i], cur);
			if (1 - cur < ans)
				ans = 1 - cur;
		}

		printf ("Case #%d: %.14lf\n", ++ ct, ans);
	}

	return 0;
}