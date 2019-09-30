#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 405
#define MAXM 4005

static int b2[MAXN];
static char b3[MAXN];
int best;
static int s[MAXN];
static int a[MAXM];
static int b[MAXN];
int N;

void DFS (int point)
{
	int i;
	if (point == 0)
	{
		int temp = 0;
		for (i = 0; i < N; i++)
		{
			if ((!b3[i]) && (b2[i])) temp++;
		}
		if (temp > best) best = temp;
		return;
	}
	int j;
	for (i = s[point]; i < s[point+1]; i++)
	{
		if ((b[a[i]] + 1) == b[point])
		{
			for (j = s[a[i]]; j < s[a[i]+1]; j++) b2[a[j]]++;
			b3[a[i]] = 1;
			DFS(a[i]);
			b3[a[i]] = 0;
			for (j = s[a[i]]; j < s[a[i]+1]; j++) b2[a[j]]--;
		}
	}
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int data[MAXM][2];
	static int q[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int M;
		scanf("%d %d",&N,&M);
		int i;
		memset(s,0,sizeof(s));
		for (i = 0; i < M; i++)
		{
			scanf("%d,%d",&(data[i][0]),&(data[i][1]));
			s[data[i][0]]++;
			s[data[i][1]]++;
		}
		for (i = 1; i <= N; i++) s[i] += s[i-1];
		for (i = 0; i < M; i++)
		{
			s[data[i][0]]--;
			a[s[data[i][0]]] = data[i][1];
			s[data[i][1]]--;
			a[s[data[i][1]]] = data[i][0];
		}
		for (i = 0; i < N; i++) b[i] = -1;
		b[0] = 0;
		q[0] = 0;
		int r = 0;
		int w = 1;
		while (w > r)
		{
			int point = q[r];
			for (i = s[point]; i < s[point+1]; i++)
			{
				if (b[a[i]] == -1)
				{
					b[a[i]] = b[point] + 1;
					q[w] = a[i];
					w++;
				}
			}
			r++;
		}
		printf("Case #%d: %d ",iT+1,b[1]-1);
		memset(b2,0,sizeof(b2));
		memset(b3,0,sizeof(b3));
		best = 0;
		DFS(1);
		printf("%d\n",best);
	}
	return 0;
}
