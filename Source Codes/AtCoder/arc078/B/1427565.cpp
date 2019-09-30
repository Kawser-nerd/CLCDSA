#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

vector<int>graph[114514], revgr[114514], hozon[114514];

int N;
vector<int>cash;
//0->N-1?????
int dfs(int v, int las)
{
	if (v == N - 1)return 0;
	int res = 114514810;
	int pus = -1;
	for (int nxt : hozon[v])
	{
		if (nxt == las)continue;
		int can = dfs(nxt, v);
		if (res > can)
		{
			res = can;
			pus = nxt;
		}
	}
	if (res < 114514)
	{
		cash.push_back(pus);
	}
	return res;
}


//??????????
int dfs2(int v, int las)
{
	int res = 1;
	for (int nxt : graph[v])
	{
		if (nxt == las)continue;
		res += dfs2(nxt, v);
	}
	return res;
}

//??????????
int dfs3(int v, int las)
{
	int res = 1;
	for (int nxt : revgr[v])
	{
		if (nxt == las)continue;
		res += dfs3(nxt, v);
	}
	return res;
}


//??????????
int dfs4(int v, int las)
{
	int res = 1;
	for (int nxt : hozon[v])
	{
		if (nxt == las)continue;
		res += dfs4(nxt, v);
	}
	return res;
}


int main(void)
{
	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int p, q;
		cin >> p >> q;
		--p; --q;
		graph[p].push_back(q);
		graph[q].push_back(p);
		revgr[p].push_back(q);
		revgr[q].push_back(p);
		hozon[p].push_back(q);
		hozon[q].push_back(p);
	}
	graph[N - 1].clear();
	revgr[0].clear();
	int X = dfs2(0, -1);
	int Z = dfs3(N - 1, -1);
	int Y = X + Z - N;
	X -= Y;
	Z -= Y;
	Y -= 2;
	//???Y??????
	bool snuke = Y % 2;

	dfs(0, -1);
	reverse(cash.begin(), cash.end());

	cash.pop_back();

	int fe = 0;
	int sn = cash.size() - 1;
	while (true)
	{
		if (sn - fe < 0)break;
		//Fe
		//X += hozon[cash[fe]].size() - 2;
		for (int nxt : hozon[cash[fe]])
		{
			int lef = ((fe == 0) ? 0 : cash[fe - 1]);
			int rht = ((fe + 1 == cash.size()) ? N-1 : cash[fe + 1]);
			if (nxt == lef || nxt == rht)continue;
			X += dfs4(nxt, cash[fe]);
		}
		Y -= hozon[cash[fe]].size() - 1;
		fe++;
		if (sn - fe < 0)break;
		//Sn
		//Z += hozon[cash[sn]].size() - 2;
		for (int nxt : hozon[cash[sn]])
		{
			int lef = ((sn == 0) ? 0 : cash[sn - 1]);
			int rht = ((sn + 1 == cash.size()) ? N-1 : cash[sn + 1]);
			if (nxt == lef || nxt == rht)continue; 
			Z += dfs4(nxt, cash[sn]);
		}
		Y -= hozon[cash[sn]].size() - 1;
		sn--;
	}

	//assert(!Y);

	snuke = cash.size() % 2;

	if (X < Z)
	{
		cout << "Snuke\n";
	}
	else if(X > Z)
	{
		cout << "Fennec\n";
	}
	else if (snuke)
	{
		cout << "Fennec\n";
	}
	else
	{
		cout << "Snuke\n";
	}
	return 0;
}