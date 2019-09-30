#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int maxn = 1000001;
int k;
int w;
int t[maxn];
int v[maxn];

void init()
{
	scanf("%d", &k);
}

void incs(int x)
{
	while (x<=k)
	{
		++t[x];
		x = (x|(x-1)) + 1;
	}
}

void decs(int x)
{
	while (x<=k)
	{
		--t[x];
		x = (x|(x-1)) + 1;
	}
}

int gett(int x)
{
	int ret = 0;
	while (x)
	{
		ret += t[x];
		x = x & (x - 1);
	}
	return ret;
}

int getm(int x)
{
	int a = 1, b = k;
	while (a < b)
	{
		int m = (a + b) >> 1;
		int ts = gett(m);
		if (ts < x)
			a = m + 1;
		else
			b = m;
	}
	return a;
}

void process()
{
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= k; ++i)
		incs(i);
	int lft = k, p = 0;
	for (int i = 1; i <= k; ++i)
	{
		p = (p + i - 1) % lft + 1;
		int ps = getm(p);
		v[ps] = i;
		decs(ps);
		--p;
		--lft;
	}
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d:", id);
	int ta;
	scanf("%d", &ta);
	for (int i = 0; i < ta; ++i)
	{
		int p;
		scanf("%d", &p);
		printf(" %d", v[p]);
	}
	printf("\n");
}

int main()
{
	freopen("c.txt", "rt", stdin);
	freopen("c_out.txt", "wt", stdout);
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
}
