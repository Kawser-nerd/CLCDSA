#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

int E, R, N;
int v[15];
int rt;

void dfs(int d, int e, int g)
{
	int i;
	if (d == N)
	{
		if (rt < g)
			rt = g;
		return;
	}
	for (i = 0; i <= e; i++)
	{
		dfs(d + 1, (e - i) + R > E ? E : (e - i) + R, g + v[d] * i);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t;
	int i, j;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d%d%d", &E, &R, &N);
		for (i = 0; i < N; i++)
			scanf("%d", &v[i]);
		rt = 0;
		dfs(0, E, 0);
		printf("%d\n", rt);
	}
	
	return 0;
}

