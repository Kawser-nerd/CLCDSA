#include <stdio.h>
#define min(a,b) a<b?a:b
int cnt[1 << 18];
int R, C, N;
int compute(int i)
{
	int ans = 0,r,c;
	for (r = 0; r < R; r++)
	{
		for (c = 0; c < C; c++)
		{
			if (c > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - 1))))
				ans++;
			if (r > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - C))))
				ans++;
		}
	}
	return ans;
}
int main() 
{
	int m,i,t;
	scanf("%d",&m);
	for (t=1;t<=m;t++)
	{
		scanf("%d %d %d",&R,&C,&N);
		int best = R * C * N * 100;
		for (i = 1; i < (1 << (R * C)); i++)
		{
			cnt[i] = cnt[i - (i & -i)] + 1;
			if (cnt[i] == N)
                               best = min(best, compute(i));
		}
		printf("Case #%d: %d\n", t, best);
	}
}
