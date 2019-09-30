#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define for_each(it, v) for (vector<int>::iterator it = (v).begin(); it != (v).end(); ++it)


const int MAX_N = 100 + 10;

int n, m;
int mem[MAX_N][MAX_N];
bool g[MAX_N][MAX_N];
bool used[MAX_N];
int linkTo[MAX_N];
vector<int> g1[MAX_N];
vector<int> g2[MAX_N];

bool findPath(int i)
{
	for (int j = 0; j < m; j++)
		if (!used[j] && g[i][j])
		{
			used[j] = true;
			if (linkTo[j] == -1 || findPath(linkTo[j]))
			{
				linkTo[j] = i;
				return true;
			}
		}
	return false;
}
int match()
{
	memset(linkTo, -1, sizeof(linkTo));
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		memset(used, 0, sizeof(used));
		if (findPath(i))
			res++;
	}
	return res;
}
bool solve(int i1, int p1, int i2, int p2)
{
	int& ans = mem[i1][i2];
	if (ans != -1)
		return ans;
	int c1 = 0, c2 = 0;
	for_each(it, g1[i1])
		if (*it != p1)
			c1++;
	for_each(it, g2[i2])
		if (*it != p2)
			c2++;
	if (c2 == 0)
		return ans = true;
	if (c1 == 0)
		return ans = false;
	if (c1 < c2)
		return ans = false;
	vector<vector<bool> > gt;
	for (int i = 0; i < c1; i++)
		gt.push_back(vector<bool> (c2, false));
	int i = 0;
	for_each(it1, g1[i1])
		if (*it1 != p1)
		{
			int j = 0;
			for_each(it2, g2[i2])
				if (*it2 != p2)
				{
					gt[i][j] = solve(*it1, i1, *it2, i2);
					j++;
				}
			i++;
		}
	for (int i = 0; i < c1; i++)
		for (int j = 0; j < c2; j++)
			g[i][j] = gt[i][j];
	n = c1;
	m = c2;
	return ans = (match() == c2);
}
int main()
{
	freopen("D-large.in", "r", stdin);
	freopen("d-large.out", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	for (int testInd = 1; testInd <= testNum; testInd++)
	{
		printf("Case #%d: ", testInd);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			g1[i].clear();
		for (int k = 0; k + 1 < n; k++)
		{
			int i, j;
			scanf("%d%d", &i, &j);
			i--, j--;
			g1[i].push_back(j);
			g1[j].push_back(i);
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			g2[i].clear();
		for (int k = 0; k + 1 < m; k++)
		{
			int i, j;
			scanf("%d%d", &i, &j);
			i--, j--;
			g2[i].push_back(j);
			g2[j].push_back(i);
		}
		bool okay = false;
		for (int i = 0; !okay && i < n; i++)
		{
			memset(mem, -1, sizeof(mem));
			if (solve(i, -1, 0, -1))
				okay = true;
		}
		if (okay)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}



