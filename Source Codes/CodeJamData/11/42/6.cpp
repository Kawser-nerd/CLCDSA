#include <stdio.h>
#include <string.h>

int n, m, d;

int dt[500][500];
int x[500][500], y[500][500];
int xsum[501][501], ysum[501][501];
int sum[501][501];

int doit ()
{
	for (int k = (n<m?n:m); k >= 3; k --)
		for (int i = 0; i + k - 1 < n; i ++)
			for (int j = 0; j + k - 1 < m; j ++)
			{
/*
				printf ("%d %d %d: %d = %d, %d = %d\n", k, i, j,
					(xsum[i+k][j+k] - xsum[i+k][j] - xsum[i][j+k] + xsum[i][j] - x[i][j] - x[i+k-1][j] - x[i][j+k-1] - x[i+k-1][j+k-1]) * 2,
					(sum[i+k][j+k] - sum[i+k][j] - sum[i][j+k] + sum[i][j] - dt[i][j] - dt[i+k-1][j] - dt[i][j+k-1] - dt[i+k-1][j+k-1]) * (i+i+k-1),
					(ysum[i+k][j+k] - ysum[i+k][j] - ysum[i][j+k] + ysum[i][j] - y[i][j] - y[i+k-1][j] - y[i][j+k-1] - y[i+k-1][j+k-1]) * 2,
					(sum[i+k][j+k] - sum[i+k][j] - sum[i][j+k] + sum[i][j] - dt[i][j] - dt[i+k-1][j] - dt[i][j+k-1] - dt[i+k-1][j+k-1]) * (j+j+k-1)
					);
*/			
				if (
					(xsum[i+k][j+k] - xsum[i+k][j] - xsum[i][j+k] + xsum[i][j] - x[i][j] - x[i+k-1][j] - x[i][j+k-1] - x[i+k-1][j+k-1]) * 2 == 
					(sum[i+k][j+k] - sum[i+k][j] - sum[i][j+k] + sum[i][j] - dt[i][j] - dt[i+k-1][j] - dt[i][j+k-1] - dt[i+k-1][j+k-1]) * (i+i+k-1)
					&&
					(ysum[i+k][j+k] - ysum[i+k][j] - ysum[i][j+k] + ysum[i][j] - y[i][j] - y[i+k-1][j] - y[i][j+k-1] - y[i+k-1][j+k-1]) * 2 == 
					(sum[i+k][j+k] - sum[i+k][j] - sum[i][j+k] + sum[i][j] - dt[i][j] - dt[i+k-1][j] - dt[i][j+k-1] - dt[i+k-1][j+k-1]) * (j+j+k-1)
					)
				return k;
			}
	return -1;
}

int main ()
{
	int t, ct = 0;

	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d%d%d", &n, &m, &d);

		memset(sum,0,sizeof(sum));
		memset(xsum,0,sizeof(xsum));
		memset(ysum,0,sizeof(ysum));

		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
			{
				char c;

				do scanf ("%c", &c); while (c <= ' ');

				dt[i][j] = c - '0';
				x[i][j] = dt[i][j] * i;
				y[i][j] = dt[i][j] * j;

				sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + dt[i][j];
				xsum[i+1][j+1] = xsum[i+1][j] + xsum[i][j+1] - xsum[i][j] + x[i][j];
				ysum[i+1][j+1] = ysum[i+1][j] + ysum[i][j+1] - ysum[i][j] + y[i][j];
			}

		int ans = doit();
		if (ans == -1)
			printf ("Case #%d: IMPOSSIBLE\n", ++ ct);
		else
			printf ("Case #%d: %d\n", ++ ct, ans);
	}

	return 0;
}
