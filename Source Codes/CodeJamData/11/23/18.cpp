#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;
int u[3000], v[3000];

vector < vector < int > > cur;
int d[2100][2100];

void add(int u, int v)
{
	for (int i = 0; i < cur.size(); i ++)
	{
		bool have_u = false, have_v = false;
		for (int j = 0; j < cur[i].size(); j ++)
		{
			if (cur[i][j] == u) have_u = true;
			if (cur[i][j] == v) have_v = true;
		}
		if (have_u && have_v)
		{
			vector < int > n1, n2;
			n1.clear(), n2.clear();
			int pu, pv;
			for (int j = 0; j < cur[i].size(); j ++)
			{
				if (cur[i][j] == u) pu = j;
				if (cur[i][j] == v) pv = j;
			}
			if (pu > pv) swap(pu, pv);
			for (int j = 0; j <= pu; j ++)
				n1.push_back(cur[i][j]);
			for (int j = pv; j < cur[i].size(); j ++)
				n1.push_back(cur[i][j]);

			for (int j = pu; j <= pv; j ++)
				n2.push_back(cur[i][j]);
			cur[i] = n1;
			cur.push_back(n2);
			d[i][cur.size() - 1] = d[cur.size() - 1][i] = true;
			break;
		}
	}
}

int mx;
int used[20];
int best = 0;

int a[20];
int b[20];

void rec(int have, int colors)
{
	if (colors > mx) return ;
	if (have == n)
	{
		if (colors <= best) return ;
		bool nice = true;
		for (int i = 0; i < cur.size(); i ++)
		{
			bool good = true;
			for (int j = 1; j <= colors; j ++)
			{
				bool ch = false;
				for (int k = 0; k < cur[i].size(); k ++)
					if (b[cur[i][k]] == j) {ch = true; break;}
				if (!ch) {good = false; break;}
			}
			if (!good)
			{
				nice = false;
				break;
			}
		}
		if (nice)
		{
			best = colors;
			for (int i = 1; i <= n; i ++)
				a[i] = b[i];
		}
		return ;
	}
	for (int i = 1; i <= colors; i ++)
		b[have + 1] = i, rec(have + 1, colors);
	if (colors + 1 <= mx)
		b[have + 1] = colors + 1, rec(have + 1, colors + 1);
}


void solve(int test)
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &u[i]);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &v[i]);

	cur.clear();
	vector < int > start;
	for (int i = 1; i <= n; i ++)
		start.push_back(i);
	cur.push_back(start);
	for (int i = 1; i <= m; i ++)
		add(u[i], v[i]);

	mx = 0;
	for (int i = 0; i < cur.size(); i ++)
		mx = max(mx, (int)cur[i].size());
	for (int i = 1; i <= mx; i ++)
		used[i] = 0;
	best = 0;
	rec(0, 0);

	printf("Case #%d: %d\n", test, best);
	/*for (int i = 1; i < n; i ++)
		printf("%d ", a[i]);
	printf("%d\n", a[n]);*/
}

int color[2100];

bool check(int C)
{
	for (int i = 0; i < cur.size(); i ++)
		for (int j = 1; j <= C; j ++)
		{
			bool have = false;
			for (int k = 0; k < cur[i].size(); k ++)
				if (color[cur[i][k]] == j) {have = true; break;}
			if (!have) return false;
		}
	return true;
}

bool pokr[2100];

void solve2(int test)
{
	for (int i = 1; i <= 2000; i ++)
		for (int j = 1; j <= 2000; j ++)
			d[i][j] = false;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &u[i]);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &v[i]);

	cur.clear();
	vector < int > start;
	for (int i = 1; i <= n; i ++)
		start.push_back(i);
	cur.push_back(start);
	for (int i = 1; i <= m; i ++)
		add(u[i], v[i]);

	mx = 10000;
	for (int i = 0; i < cur.size(); i ++)
		mx = min(mx, (int)cur[i].size());

	printf("Case #%d: %d\n", test, mx);

	for (int i = 1; i <= n; i ++)
		color[i] = 0;
	for (int i = 0; i < cur.size(); i ++)
		pokr[i] = false;

	for (int i = 0; i < cur.size(); i ++)
		if (cur[i].size() == mx)
		{
			for (int j = 0; j < cur[i].size(); j ++)
				color[cur[i][j]] = j + 1;
			pokr[i] = true;
			break;
		}

	while (true)
	{
		int v = -1;
		for (int i = 0; i < cur.size(); i ++)
			if (!pokr[i])
			{
				int rask = 0;
				for (int j = 0; j < cur[i].size(); j ++)
					if (color[cur[i][j]] != 0) rask ++;
				if (rask >= 2)
				{
					v = i;
					break;
				}
			}
		if (v == -1) break;
		pokr[v] = true;

		vector < int > have; have.clear();
		for (int i = 1; i <= mx; i ++)
		{
			bool good = false;
			for (int j = 0; j < cur[v].size(); j ++)
				if (color[cur[v][j]] == i) {good = true; break;}
			if (!good) have.push_back(i); 
		}

		vector < int > index; index.clear();
		for (int j = 0; j < cur[v].size(); j ++)
			if (color[cur[v][j]] == 0) index.push_back(j);

		for (int j = 0; j < have.size(); j ++)
			color[cur[v][index[j]]] = have[j];
		vector < int > nindex; nindex.clear();
		for (int j = have.size(); j < index.size(); j ++)
			nindex.push_back(index[j]);
		index = nindex;
		if (index.size() == 0) continue;
		int s = color[cur[v][(index[0] - 1 + cur[v].size()) % cur[v].size()]];
		int t = color[cur[v][(index.back() + 1) % cur[v].size()]];
		if (s == t)
		{
			int p = 1;
			if (s == 1) p = 2;
			for (int j = 0; j + 1 < index.size(); j ++)
				if (j % 2 == 0) color[cur[v][index[j]]] = p; else 
					color[cur[v][index[j]]] = s;
			if (p == 1)
			{
				if (s == 2) 
					color[cur[v][index.back()]] = 3; else 
					color[cur[v][index.back()]] = 2;
			} else
			{
				color[cur[v][index.back()]] = 3;
			}
		} else
		{
			int p = 1;
			if (s == 1) p = 2;
			int pr = s, pv = t;
			for (int j = 0; j + 1 < index.size(); j ++)
				if (j % 2 == 0) color[cur[v][index[j]]] = p, pr = p; else 
					color[cur[v][index[j]]] = s, pr = s;
			for (int j = 1; j <= 3; j ++)
				if (j != pr && j != pv)
				{
					color[cur[v][index.back()]] = j;
					break;
				}
		}
	}
	for (int i = 1; i < n; i ++)
		printf("%d ", color[i]);
	printf("%d\n", color[n]);
	if (!check(mx)) cout << "BAD!!!!!!" << endl;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	scanf("%d\n", &test);
	for (int i = 1; i <= test; i ++)
	{
		//solve(i);
		solve2(i);
		cerr << i << endl;
	}
	return 0;
}