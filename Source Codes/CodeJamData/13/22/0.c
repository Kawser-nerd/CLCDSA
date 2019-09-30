#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 3005

int module (int a)
{
	if (a < 0) return -a;
	else return a;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static long double a[MAXN][MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N, X, Y;
		scanf("%d %d %d",&N,&X,&Y);
		int lv = 0;
		int prev = 0;
		int next = 1;
		while (1)
		{
			if ((prev+next) >= N) break;
			prev += next;
			next += 4;
			lv++;
		}
		int cnt = next / 2;
		N -= prev;
		//printf("lv = %d, cnt = %d, N = %d\n",lv,cnt,N);
		int needlv = (module(X) + Y) / 2;
		long double res;
		if (needlv < lv) res = 1.0;
		else if (needlv > lv) res = 0.0;
		else
		{
			if (N == (cnt * 2 + 1)) res = 1.0;
			else if (Y == cnt) res = 0.0;
			else
			{
				memset(a,0,sizeof(a));
				a[0][0] = 1.0;
				int len, l, r;
				for (len = 0; len < N; len++)
				{
					for (l = 0; l <= len; l++)
					{
						r = len - l;
						if ((l >= 0) && (l <= cnt) && (r >= 0) && (r <= cnt))
						{
							//printf("a[%d][%d] = %.9f\n",l,r,(double)a[l][r]);
							if ((l < cnt) && (r < cnt))
							{
								a[l+1][r] += a[l][r] * 0.5;
								a[l][r+1] += a[l][r] * 0.5;
							}
							else if (l < cnt)
							{
								a[l+1][r] += a[l][r];
							}
							else if (r < cnt)
							{
								a[l][r+1] += a[l][r];
							}
						}
					}
				}
				res = 0.0;
				for (l = Y+1; l <= cnt; l++)
				{
					r = N - l;
					if ((r >= 0) && (r <= cnt)) res += a[l][r];
				}
			}
		}
		printf("Case #%d: %.9lf\n",(iT+1),(double)(res));
	}
	return 0;
}