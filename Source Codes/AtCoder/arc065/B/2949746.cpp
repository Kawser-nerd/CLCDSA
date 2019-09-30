#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
int n, k, l;
int tar[2 * N], nex[2 * N], fir[N], cnt;
int bel[N], sum[N], ans[N], stk[N], vis[N], top;
int Getbel(int x)
{
	if (!bel[x])
		return x;
	return bel[x] = Getbel(bel[x]);
}
void add(int a, int b)
{
	++cnt;
	tar[cnt] = b;
	nex[cnt] = fir[a];
	fir[a] = cnt;
}
void dfs(int r)
{
	vis[r] = 1;
	stk[++top] = r;
	for (int i = fir[r]; i; i = nex[i])
	{
		int v = tar[i];
		if (!vis[v])
			dfs(v);
	}
}
int main()
{
	scanf("%d%d%d", &n, &k, &l);
	for (int i = 1; i <= k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a = Getbel(a), b = Getbel(b);
		if (a != b)
			bel[a] = b;
	}
	for (int i = 1; i <= l; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			for (int j = 1; j <= top; j++)
				sum[Getbel(stk[j])]++;
			for (int j = 1; j <= top; j++)
				ans[stk[j]] = sum[Getbel(stk[j])];
			for (int j = 1; j <= top; j++)
				sum[Getbel(stk[j])]--;
			top = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], i == n ? 10 : 32);
}