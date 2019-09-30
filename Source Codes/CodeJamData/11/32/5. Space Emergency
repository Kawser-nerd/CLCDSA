#include <iostream>
#include <algorithm>
using namespace std;

double d[1000006], dis[1000006];
int a[1000006];

int main()
{
	int ncase;
	int icase;
	int l, n, c;
	int i, j, k;
	long long t;
	double res;
	double time;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		// l: eng, t: bt, n: star
		scanf("%d %I64d %d %d", &l, &t, &n, &c);

		for(i = 0;i < c;i++)
			scanf("%d", &a[i]);

		j = 0;
		res = 0;
		for(i = 0;i < n;i++)
		{
			d[i] = a[j++];
			res += d[i] * 2;
			if (j >= c)
				j = 0;
		}


		// double time
		time = 0;
		for(i = 0;i < n;i++)
		{
			time += d[i] * 2;
			if (time > t)
				break;
		}

		if (i < n)
		{
			dis[0] = d[i] - (t - (time - d[i] * 2)) * 0.5;

			for(k = 1, j = i + 1;j < n;j++, k++)
				dis[k] = d[j];

			sort(&dis[0], &dis[k]);

			for(i = 0;i < l && k - 1 - i >= 0;i++)
			{
				res -= dis[k - 1 - i] * 2;
				res += dis[k - 1 - i];
			}
		}

		printf("Case #%d: %.0lf\n", icase, res);
	}
	return 0;
}
