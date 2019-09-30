/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int tests;
int ts;
int r, c;
vector<pair<int, int> > ways;
int found;
int board[200][200];
vector<int> g[1200];
int used[1000];

int get_id(int a, int b, int c)
{
	return (a * 20 + b) * 2 + c;
}

void add_edge(int a, int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

bool good(int mask)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (mask % 2) // /

			{
				board[i][j] = 1;
			}
			else
			{
				board[i][j] = 0;
			}
			mask /= 2;
		}
	}
	
	for (int i = 0; i <= 1000; i++)
	{
		g[i].clear();
	}
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 1)// /
			{
				add_edge(get_id(i, j, 0), get_id(i, j, 1));
				add_edge(get_id(i, j + 1, 1), get_id(i + 1, j, 0));
			}
			else
			{
				add_edge(get_id(i, j + 1, 1), get_id(i, j, 0));
				add_edge(get_id(i, j, 1), get_id(i + 1, j, 0));
			}
		}
	}

	vector<int > whr;

	whr.clear();
	for (int i = 0; i < c; i++)
	{
		whr.push_back(get_id(0, i, 0));
	}
	for (int i = 0; i < r; i++)
	{
		whr.push_back(get_id(i, c, 1));
	}
	for (int i = c - 1; i >= 0; --i)
	{
		whr.push_back(get_id(r, i, 0));
	}
	for (int i = r - 1; i >= 0; --i)
	{
		whr.push_back(get_id(i, 0, 1));
	}

	for (int i = 0; i < ways.size(); i++)
	{
		for (int j = 0; j <= 800; j++)
		{
			used[j] = 0;
		}
		dfs(whr[ways[i].first]);
		if (!used[whr[ways[i].second]])
			return false;
	}
	return true;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		++ts;
		cerr << ts << endl;
		cin >> r >> c;
		int perim = (r + c) * 2;
		ways.clear();
		for (int i = 0; i < perim / 2; i++)
		{
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			ways.push_back(make_pair(a, b));
		}
		found = -1;
		for (int mask = 0; mask < (1 << (r*c)); mask++)
		{
			if (good(mask))
				found = mask;
		}
		cout << "Case #" << ts << ":" << endl;
		if (found == -1)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (found % 2)
					cout << "/";
				else
					cout << "\\";
				found /= 2;
			}
			cout << endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}