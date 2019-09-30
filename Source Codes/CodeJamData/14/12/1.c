#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 2005
#define MYINF 1000000000

struct node
{
	int a, b;
};

static int a[MAXN];
static int s[MAXN];
static int cnt[MAXN];
static int val[MAXN];

void DFS (int point, int par)
{
	int childs = 0;
	int i;
	cnt[point] = 1;
	val[point] = 0;
	int max1, max2;
	max1 = 0; max2 = 0;
	for (i = s[point]; i < s[point+1]; i++)
	{
		if (a[i] != par)
		{
			DFS(a[i], point);
			childs++;
			cnt[point] += cnt[a[i]];
			val[point] += cnt[a[i]];
			int temp = cnt[a[i]] - val[a[i]];
			if (temp > max1)
			{
				max2 = max1;
				max1 = temp;
			}
			else if (temp > max2)
			{
				max2 = temp;
			}
		}
	}
	if (childs >= 2) val[point] = val[point] - max1 - max2;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static struct node data[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N, M;
		scanf("%d",&N);
		M = N-1;
		memset(s,0,sizeof(s));
		int i;
		for (i = 0; i < M; i++)
		{
			scanf("%d %d",&(data[i].a),&(data[i].b));
			data[i].a--;
			s[data[i].a]++;
			data[i].b--;
			s[data[i].b]++;
		}
		for (i = 1; i <= N; i++) s[i] += s[i-1];
		for (i = 0; i < M; i++)
		{
			s[data[i].a]--;
			a[s[data[i].a]] = data[i].b;
			s[data[i].b]--;
			a[s[data[i].b]] = data[i].a;
		}
		int res = MYINF;
		for (i = 0; i < N; i++)
		{
			DFS(i, -1);
			if (val[i] < res) res = val[i];
		}
		printf("Case #%d: %d\n",iT+1,res);
	}
	return 0;
}
