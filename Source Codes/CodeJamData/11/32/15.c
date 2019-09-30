#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define INF	1000000000

int main()
{
	int T, t_case;
	scanf("%d", &t_case);
	for (T = 1; T <= t_case; T++)
	{
		int l, t, n, c;
		int a[MAX_N];
		int d[MAX_N];
		scanf("%d %d %d %d", &l, &t, &n, &c);
		int i, j;
		int ans = INF;		
		for (i = 0; i < c; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			d[i] = a[i % c];
		for (i = 0; i < n; i++)
			for (j = i; j < n; j++)
			{
				int tmp = 0;
				int k;
				for (k = 0; k < n; k++)
					if ((k == i && l >= 1) || (k == j && l == 2))
					{
						if (tmp >= t)
							tmp += d[k];
						else if (tmp + d[k] * 2 >= t)
							tmp = t + (d[k] - (t - tmp) / 2);
						else
							tmp += d[k] * 2;
					}
					else
						tmp += d[k] * 2;
				ans = ans < tmp ? ans : tmp;			
			}	
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}
