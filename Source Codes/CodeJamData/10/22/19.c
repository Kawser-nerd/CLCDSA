#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    int T, tt;
    
    scanf("%d", &T);
    for (tt = 1; tt <= T; tt++) {
        // code

long cnt, k, b, t;
long x[100], v[100];
long dp[51][1001];

scanf("%ld %ld %ld %ld", &cnt, &k, &b, &t);
for (int i = 0; i < cnt; i++)
{
	scanf("%ld", &x[i]);
}
for (int i = 0; i < cnt; i++)
{
	scanf("%ld", &v[i]);
}
memset(dp, 0, sizeof(dp));
for (int i = cnt-1; i >= 0; i--)
{
	long minT = ((b-x[i])==0?0:((b-x[i]-1)/v[i]) + 1);
	for (int j = minT; j <= t; j++)
	{
		dp[i][j] = 1;
	}
}
long min[51];
min[cnt-1] = 0;
//printf("%d:%ld\n", cnt-1, dp[cnt-1][t]);
for (int i = cnt-2; i >= 0; i--)
{
//printf("%d:%ld\n", i, dp[i][t]);
	min[i] = min[i+1] + (dp[i+1][t]? 0: 1);
}
//printf("k=%ld\n", k);
long p = k;
long res = 0;
if (p > 0)
{
	for (int i = cnt-1; i>=0; i--)
	{
		if (dp[i][t] > 0)
		{
			res += min[i];
			p--;
			if (p == 0) break;
		}
	}
}
//printf("p=%ld\n", p);
        printf("Case #%d: ", tt);
        // result
        if (p == 0)
	printf("%ld\n", res);
	else
        printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
