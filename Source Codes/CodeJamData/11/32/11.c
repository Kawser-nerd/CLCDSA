#include <assert.h>
#include <stdio.h>
#include <limits.h>

int tabel[1001];
int dp[1001][3];
int l, t, n, c;

int main()
{
	int T;
	scanf("%i", &T);
	for (int test = 1; test <= T; test++)
	{
		scanf("%i %i %i %i", &l, &t, &n, &c);
		for (int i = 0; i < c; i++)
		{
			int a;
			scanf("%i", &a);
			for (int j = 0; j * c + i < n; j++)
				tabel[j * c + i + 1] = a;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= l; j++) 
			{
				dp[i][j] = dp[i - 1][j] + 2 * tabel[i];
				if (j >= 1)
				{
					int m = dp[i - 1][j - 1];
					int dt = t - m;
					m += tabel[i];
					if (dt > 0)
					{
						assert(dt % 2 == 0);
						m += dt / 2;
					}
					if (m < dp[i][j])
						dp[i][j] = m;
				}
			}
		}
		printf("Case #%i: %i\n", test, dp[n][l]);
	}
	return 0;
}
