#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 205

struct node
{
	long long int pos;
	int cnt;	
};

static struct node a[MAXN];
int N;
long long int D;

char Check (long long int T)
{
	long long int last = -10000000000000LL;
	int i;
	long long int min, max, t;
	for (i = 0; i < N; i++)
	{
		min = last + D;
		max = last + D * (long long int)(a[i].cnt);
		if ((max - a[i].pos) > T) return 0;
		if (a[i].pos <= min) last = max;
		else
		{
			t = a[i].pos - min;
			if (t > T)
			{
				min = a[i].pos - T;
				max = min + D * (long long int)(a[i].cnt - 1);
			}
			t = max - a[i].pos;
			if (t > T) return 0;
			last = max;
		}
	}
	return 1;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		scanf("%d %I64i",&N,&D);
		D *= 2LL;
		int i;
		for (i = 0; i < N; i++)
		{
			scanf("%I64i %d",&(a[i].pos),&(a[i].cnt));
			(a[i].pos) *= 2LL;
		}
		long long int l, r, c;
		l = 0LL; r = 10000000000000LL;
		while (r > l)
		{
			c = (l + r) / 2LL;
			if (Check(c)) r = c;
			else l = c + 1LL;
		}
		printf("Case #%d: %I64i.",iT+1,l/2LL);
		if (l % 2LL) printf("5\n");
		else printf("0\n");
	}
	return 0;
}