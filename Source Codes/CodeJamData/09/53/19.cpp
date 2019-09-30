#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

ifstream fin("c-large.in.txt");
ofstream fout("r3c.out");

int T;
int N;
pair<int, int> list[2000];
int c[2000];
int q[2000];
int d[2000];
int actd[2000];
bool dontcare[2000];
int g[2000][2000];
int actN;

void link(int i, int j)
{
	g[i][d[i]++]=j;
	g[j][d[j]++] = i;
}

void buildgraph()
{
	memset(d, 0, sizeof d);
	memset(g, 0, sizeof g);
	for (int i=0; i<N; i++)
		for (int fix=-1; fix<=1; fix++)
			for (int j=i+1; j<N; j++)
			{
				if (list[j].second == list[i].second+fix)
				{
					link(i,j);
					break;
				}
			}
}


bool test1()
{
	for (int i=0; i<N; i++)
		if (d[i] > 0) return false;
	return true;
}

bool test2()
{
	memset(c, 0, sizeof c);
	for (int i=0; i<N; i++)
		if (c[i] == 0)
		{
			int cl = 0, op = 1;
			c[i] = 1;
			q[0] = i;
			while (cl < op)
			{
				for (int j=0; j<d[q[cl]]; j++)
				{
					if (c[g[q[cl]][j]] == 0)
					{
						c[g[q[cl]][j]] = 3-c[q[cl]];
						q[op++] = j;
					}
					else if (c[g[q[cl]][j]] != 3-c[q[cl]]) return false;
				}
				cl++;
			}
		}
	return true;
}

void shrink()
{
	memset(dontcare, false, sizeof dontcare);
	int op = 0;
	int cl = 0;
	for (int i=0; i<N; i++)
		if (d[i] <= 2)
		{
			dontcare[i] = true;
			q[op++] = i;
		}
		memcpy(actd, d, sizeof d);
		while (cl < op)
		{
			for (int i=0; i<d[q[cl]]; i++)
				if (!dontcare[g[q[cl]][i]])
				{
					actd[g[q[cl]][i]]--;
					if (actd[g[q[cl]][i]] <= 2)
					{
						dontcare[g[q[cl]][i]] = true;
						q[op++] = g[q[cl]][i];
					}
				}
				cl++;
		}
		actN = N - op;
}

int tc = 0;

bool depth(int dep)
{
	if (dep >= actN) 
	{
		/*for (int i=0; i<N; i++)
			for (int j=0; j<d[i]; j++)
				if (c[i] == c[g[i][j]])
				{
					cerr << c[i] << ' ' << c[g[i][j]] << "ERROR"<<endl;
				}*/
				return true;
	}
	bool vis[3];
	int mincnt = 100;
	int chosen = -1;
	for (int i=0; i<N; i++)
		if (!dontcare[i] && c[i] == 0)
		{
			memset(vis, 0, sizeof vis);
			for (int j=0; j<d[i]; j++)
				if (c[g[i][j]] > 0)
				{
					vis[c[g[i][j]]-1] = true;
				}
				int cnt = 0;
				for (int k=0; k<tc; k++)
					if (!vis[k]) cnt++;
				if (cnt == 0) return false;
				if (cnt < mincnt)
				{
					mincnt = cnt;
					chosen = i;
					if (mincnt==1) break;
				}

		}
		{
			int i =chosen;
			memset(vis, 0, sizeof vis);
			for (int j=0; j<d[i]; j++)
				if (c[g[i][j]] > 0)
				{
					vis[c[g[i][j]]-1] = true;
				}
				for (int k=0; k<tc; k++)
					if (!vis[k])
					{
						c[i] = k+1;
						if (depth(dep+1)) return true;
						c[i] = 0;
					}
		}
		return false;
}


bool test3()
{
	if (tc == 3) shrink(); else {actN = N;memset(dontcare, false, sizeof dontcare);}
	memset(c, 0, sizeof c);
	if (depth(0))	return true;else return false;
}

int main()
{
	fin >> T;
	int cases = 0;
	while (T--)
	{
		fin >> N;
		for (int i=0; i<N; i++) fin >> list[i].first >> list[i].second;
		sort(list, list+N);
		int ans = 4;
		buildgraph();
		for (tc=1; tc<=3; tc++)
			if (test3())
			{
				ans = tc;
				break;
			}
		/*
		if (test1())
		{
			ans =1;
		}
		else if (test2())
		{
			ans =2;
		}
		else if (test3())
		{
			ans = 3;
		}
		else ans = 4;
		*/
		fout << "Case #" << ++cases << ": " << ans << endl;
	}
	return 0;
}