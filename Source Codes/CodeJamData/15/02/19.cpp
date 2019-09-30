#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 0x7f7f7f7f
#define MAXN 1005
int cas, n, limit, ans; int a[MAXN];
int f[MAXN][MAXN];

int main()
{
	freopen("B.in", "r", stdin); freopen("B.out", "w", stdout);
	for (int i = 1; i <= 1000; i ++)
		for (int j = 1; j <= 1000; j ++)
			if (j <= i)
				f[i][j] = 0;
			else
			{
				f[i][j] = INF;
				for (int k = 1; k < j; k ++)
					f[i][j] = min(f[i][k] + f[i][j - k] + 1, f[i][j]);
			}
	scanf("%d", &cas);
	for (int T = 1; T <= cas; T ++)
	{
		scanf("%d", &n); limit = 0;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", &a[i]);
			limit = max(a[i], limit);
		}
		ans = INF;
		for (int j = 1; j <= limit; j ++)
		{
			int tmp = j;
			for (int i = 1; i <= n; i ++)
				tmp += f[j][a[i]];
			ans = min(tmp, ans);
		}
		printf("Case #%d: %d\n", T, ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
