#include<stdio.h>

long long coins[100], denom[10000];

int main()
{
	int C, count, D, i, j, k, t, T;
	long long newdenom, num, V;
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d %d %lld", &C, &D, &V);
		for (i = 0; i < D; i++)
			scanf("%lld", &coins[i]);
		k = 0;
		for (i = 0; i < D; i++)
			for (j = 0; j < C; j++)
				denom[k++] = coins[i];
		count = 0;
		num = 1;
		i = 0;
		while (num <= V)
		{
			if ((i < k) && (denom[i] <= num))
			{
				num += denom[i];
				i++;
			}
			else
			{
				newdenom = num;
				num += newdenom * C;
				count++;
			}
		}
		printf("Case #%d: %d\n", t, count);
	}
	return 0;
}