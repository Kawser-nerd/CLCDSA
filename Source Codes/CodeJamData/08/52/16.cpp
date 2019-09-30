#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define VI vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define all(v) v.begin(), v.end()

#define NMAX 16
#define INF 10000

char dx[4] = {0, 1, 0, -1};
char dy[4] = {1, 0, -1, 0};

struct State
{
	char x, y, x1, y1, x2, y2;
};

short d[NMAX][NMAX][NMAX][NMAX][NMAX][NMAX];
bool used[NMAX][NMAX][NMAX][NMAX][NMAX][NMAX];
int n, m;
queue<State> q;
string a[NMAX];

bool valid(char x, char y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

void update(const State& u, const State& v, short w)
{
	if (d[u.x][u.y][u.x1][u.y1][u.x2][u.y2] + w >= d[v.x][v.y][v.x1][v.y1][v.x2][v.y2]) return;
	d[v.x][v.y][v.x1][v.y1][v.x2][v.y2] = d[u.x][u.y][u.x1][u.y1][u.x2][u.y2] + w;
	if (used[v.x][v.y][v.x1][v.y1][v.x2][v.y2]) return;
	used[v.x][v.y][v.x1][v.y1][v.x2][v.y2] = true;
	q.push(v);
}

void solve(int tc)
{
	cerr << tc << endl;
	cin >> n >> m;
	forn(i, n) cin >> a[i];
	forn(i, n + 1) forn(j, m + 1) forn(i1, n + 1) forn(j1, m + 1) forn(i2, n + 1) forn(j2, m + 1)
	{
		d[i][j][i1][j1][i2][j2] = INF;		
		used[i][j][i1][j1][i2][j2] = false;
	}
	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i][j] == 'O')
			{
				d[i][j][n][m][n][m] = 0;
				used[i][j][n][m][n][m] = true;
				State s = {i, j, n, m, n, m};
				q.push(s);
			}
		}
	}
	State u, v;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		used[u.x][u.y][u.x1][u.y1][u.x2][u.y2] = false;
		//create blue portal
		v = u;
		forn(i, 4)
		{
			v.x1 = u.x;
			v.y1 = u.y;
			while (valid(v.x1, v.y1))
			{
				if (a[v.x1][v.y1] == '#')
				{
					break;
				}
				v.x1 += dx[i];
				v.y1 += dy[i];
			}
			v.x1 -= dx[i];
			v.y1 -= dy[i];
			update(u, v, 0);
		}	
		//create yellow portal
		v = u;
		forn(i, 4)
		{
			v.x2 = u.x;
			v.y2 = u.y;
			while (valid(v.x2, v.y2))
			{
				if (a[v.x2][v.y2] == '#')
				{
					break;
				}
				v.x2 += dx[i];
				v.y2 += dy[i];
			}
			v.x2 -= dx[i];
			v.y2 -= dy[i];
			update(u, v, 0);
		}	
		//ordinary move
		v = u;
		forn(i, 4)
		{
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];
			if (!valid(v.x, v.y) || a[v.x][v.y] == '#') continue;
			update(u, v, 1);			
		}
		//use blue portal
		v = u;
		if (u.x == u.x1 && u.y == u.y1 && u.x2 < n)
		{
			v.x = u.x2;
			v.y = u.y2;
			update(u, v, 1);
		}
		//use yellow portal
		v = u;
		if (u.x == u.x2 && u.y == u.y2 && u.x1 < n)
		{
			v.x = u.x1;
			v.y = u.y1;
			update(u, v, 1);
		}
	}

	short ans = INF;
	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i][j] != 'X') continue;
			forn(i1, n + 1)
			{
				forn(j1, m + 1)
				{
					forn(i2, n + 1)
					{
						forn(j2, m + 1)
						{
							ans = min(ans, d[i][j][i1][j1][i2][j2]);
						}
					}
				}
			}
		}
	}
	printf("Case #%d: ", tc);
	if (ans < INF) printf("%d\n", ans); else printf("THE CAKE IS A LIE\n"); 
}

int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);
	int tc;
	cin >> tc;
	for1(i, tc) solve(i);	
	return 0;
}
         	
