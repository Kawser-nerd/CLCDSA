#include <stdio.h>
#include <string.h>

int release[10001];
int b[102], sum[102];
int c, p, q;

void read()
{
	int i, count, a;
	scanf("%d%d", &p, &q);
	memset(release, 0, sizeof(release));
	for(i = 0; i < q; i++)
	{
		scanf("%d", &a);
		release[a] = 1;
	}
	count = 0;
	c = 0;
	sum[0] = -1;
	for(i = 1; i <= p; i++)
		if(release[i])
		{
			b[++c] = count;
			sum[c] = sum[c - 1] + count + 1;
			count = 0;
		}
		else
			count++;
	b[++c] = count;
	sum[c] = sum[c - 1] + count + 1;
}

int f[102][102];

void solve()
{
	int i, j, k;
	for(j = 1; j < c; j++)f[2][j] = b[j] + b[j + 1];
	for(i = 3; i <= c; i++)
		for(j = 1; j <= c - i + 1; j++)
		{
			int min = f[1][j] + f[i - 1][j + 1];
			for(k = 2; k < i; k++)
				if(f[k][j] + f[i - k][j + k] < min)min = f[k][j] + f[i - k][j + k];
			f[i][j] = min + sum[i + j - 1] - sum[j - 1] - 2;
		}
	printf(" %d\n", f[c][1]);
}

int main()
{
	int n, testcase;
//	freopen("C.in", "r", stdin);
	scanf("%d", &n);
	for(testcase = 1; testcase <= n; testcase++)
	{
		printf("Case #%d:", testcase);
		read();
		solve();
	}
	return 0;
} 
