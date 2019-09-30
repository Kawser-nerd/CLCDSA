#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

int ans;
__int64 a, b, p;
bool isP[1000001];
__int64 prs[1000001];
int tpr = 0;
int pr[1000001];
int par[1000001];

void prepare()
{
	memset(isP, true, sizeof(isP));
	for (int i = 2; i < 1000000; ++i)
	{
		if (isP[i])
		{
			prs[tpr++] = i;
			for (int j = 2; i * j < 1000000; ++j)
				isP[i*j] = false;
		}
	}
}

void init()
{
	scanf("%I64d%I64d%I64d", &a, &b, &p);
}

int findP(int x)
{
	if (par[x]!=x) par[x] = findP(par[x]);
	return par[x];
}

void process()
{
	for (int i = 0; i <= b-a; ++i)
		par[i] = i;
	for (int i = 0; i < tpr; ++i)
	{
		__int64 curp = prs[i];
		if (curp>=p)
		{
			__int64 st = (a+curp-1)/curp*curp;
			while (st+curp<=b)
			{
				par[findP(st+curp-a)] = findP(st-a);
				st += curp;
			}
		}
	}
	ans = 0;
	for (int i = 0; i <= b - a; ++i)
		if (findP(i) == i)
			++ans;
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d: %d\n", id, ans);
}

int main()
{
	prepare();
	freopen("b.txt", "rt", stdin);
	freopen("b_out.txt", "wt", stdout);
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
}
