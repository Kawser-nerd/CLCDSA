#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 10005

int Min (int a, int b)
{
	if (a < b) return a;
	else return b;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int a[MAXN];
	static int b[MAXN];
	static int A[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N;
		scanf("%d",&N);
		memset(A,0,sizeof(A));
		int i, j;
		for (i = 0; i < N; i++)
		{
			scanf("%d",&j);
			(A[j])++;
		}
		int l, r, c;
		l = 0; r = N;
		char flag;
		while (r > l)
		{
			c = (l+r+1)/2;
			flag = 1;
			memcpy(a,A,sizeof(A));
			memset(b,0,sizeof(b));
			for (i = 1; i <= 10000; i++)
			{
				b[i+1] += Min(b[i], a[i]);
				a[i] -= Min(b[i], a[i]);
				if (a[i] > 0)
				{
					int now = a[i];
					for (j = i; j < i+c; j++)
					{
						if (a[j] < now)
						{
							flag = 0;
							break;
						}
						a[j] -= now;
					}
					b[i+c] += now;
				}
				if (!flag) break;
			}
			if (flag) l = c;
			else r = c-1;
		}
		printf("Case #%d: %d\n",iT+1,l);
	}
	return 0;
}
