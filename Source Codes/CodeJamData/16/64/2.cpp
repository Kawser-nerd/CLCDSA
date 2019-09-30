#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, -1, 1};

const int N = 1005;
char f[N][N];

int qu[N * N][2];
int dT[N][N];
int usedT[N][N];
int timerT = 146;
int d[N][N];
int used[N][N];
int timer = 146;
bool never[N][N];

bool flag(int x, int y)
{
	return f[x][y] == '#';
}

bool bad(int x, int y)
{
	bool f00 = flag(x, y);
	bool f01 = flag(x, y + 1);
	bool f10 = flag(x + 1, y);
	bool f11 = flag(x + 1, y + 1);
	return (f00 == f11 && f01 == f10 && f00 != f01);
}

int bfsT(int sx, int sy, int tx, int ty, bool bf, int cx, int cy)
{
	int sz = 0;
	if (!bf)
	{
		timerT++;
		qu[sz][0] = sx;
		qu[sz][1] = sy;
		usedT[sx][sy] = timerT;
		dT[sx][sy] = 0;
		sz++;
	}
	else if (cx == -1)
	{
		return dT[tx][ty];
	}
	else
	{
		usedT[cx][cy] = timerT;
		dT[cx][cy] = N * N;
		for (int dd = 0; dd < 4; dd++)
		{
			int nx = cx + DX[dd];
			int ny = cy + DY[dd];
			if (usedT[nx][ny] != timerT) continue;
			dT[cx][cy] = min(dT[cx][cy], dT[nx][ny] + 1);
		}
		qu[sz][0] = cx;
		qu[sz][1] = cy;
		sz++;
	}
	for (int t = 0; t < sz; t++)
	{
		int x = qu[t][0];
		int y = qu[t][1];
//		eprintf("x = %d, y = %d\n", x, y);
		for (int dd = 0; dd < 4; dd++)
		{
			int nx = x + DX[dd];
			int ny = y + DY[dd];
			if (f[nx][ny] == '#') continue;
			if (usedT[nx][ny] == timerT && dT[nx][ny] <= dT[x][y] + 1) continue;
			usedT[nx][ny] = timerT;
			qu[sz][0] = nx;
			qu[sz][1] = ny;
			sz++;
			dT[nx][ny] = dT[x][y] + 1;
		}
	}
	return dT[tx][ty];	
}

int bfs(int sx, int sy, int tx, int ty, bool bf, int cx, int cy)
{
	int sz = 0;
	if (!bf)
	{
		timer++;
		qu[sz][0] = sx;
		qu[sz][1] = sy;
		used[sx][sy] = timer;
		d[sx][sy] = 0;
		sz++;
	}
	else if (cx == -1)
	{
		return d[tx][ty];
	}
	else
	{
		used[cx][cy] = timer;
		d[cx][cy] = N * N;
		for (int dd = 0; dd < 4; dd++)
		{
			int nx = cx + DX[dd];
			int ny = cy + DY[dd];
			if (used[nx][ny] != timer) continue;
			d[cx][cy] = min(d[cx][cy], d[nx][ny] + 1);
		}
		qu[sz][0] = cx;
		qu[sz][1] = cy;
		sz++;
	}
	for (int t = 0; t < sz; t++)
	{
		int x = qu[t][0];
		int y = qu[t][1];
//		eprintf("x = %d, y = %d\n", x, y);
		for (int dd = 0; dd < 4; dd++)
		{
			int nx = x + DX[dd];
			int ny = y + DY[dd];
			if (f[nx][ny] == '#') continue;
			if (used[nx][ny] == timer && d[nx][ny] <= d[x][y] + 1) continue;
			used[nx][ny] = timer;
			qu[sz][0] = nx;
			qu[sz][1] = ny;
			sz++;
			d[nx][ny] = d[x][y] + 1;
		}
	}
	return d[tx][ty];	
}

void solve()
{
	memset(never, false, sizeof never);
	int di, r, c;
	scanf("%d%d%d", &r, &c, &di);
	for (int i = 0; i < r; i++)
		scanf("%s", f[i] );
	int sx = 0, sy = 0, tx = 0, ty = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (f[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			if (f[i][j] == 'F')
			{
				tx = i;
				ty = j;
			}
		}
	{
		int curD = bfs(sx, sy, tx, ty, false, -1, -1);
		bfsT(tx, ty, sx, sy, false, -1, -1);
//		eprintf("curD = %d\n", curD);
		if (curD < di || curD % 2 != di % 2 || abs(sx - tx) + abs(sy - ty) > di)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}

	bool BF = false;
	while (true)
	{
		int curD = bfs(sx, sy, tx, ty, BF, -1, -1);
		bfsT(tx, ty, sx, sy, BF, -1, -1);
		BF = true;
//		eprintf("curD = %d\n", curD);
		if (curD < di || curD % 2 != di % 2)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
		if (curD == di) break;
		bool fl = false;
		for (int i = 1; i < r - 1 && !fl; i++)
			for (int j = 1; j < c - 1 && !fl; j++)
			{
				if (f[i][j] != '#' || never[i][j] ) continue;
				f[i][j] = '.';
				bool bd = false;
				for (int ii = i - 1; ii <= i; ii++)
					for (int jj = j - 1; jj <= j; jj++)
					{
						if (bad(ii, jj) )
							bd = true;
					}
				if (bd)
				{
					f[i][j] = '#';
					continue;
				}
				int XX = di;
				for (int d1 = 0; d1 < 4; d1++)
					for (int d2 = 0; d2 < 4; d2++)
					{
						int x1 = i + DX[d1];
						int y1 = j + DY[d1];
						int x2 = i + DX[d2];
						int y2 = j + DY[d2];
						if (used[x1][y1] != timer || usedT[x2][y2] != timerT) continue;
						XX = min(XX, d[x1][y1] + dT[x2][y2] + 2);
					}
				if (XX < di)
				{
					never[i][j] = true;
					f[i][j] = '#';
					continue;
				}
				bfs(sx, sy, tx, ty, BF, i, j);
				bfsT(tx, ty, sx, sy, BF, i, j);
				BF = true;
				fl = true;
			}
		if (!fl)
		{
			eprintf("curD = %d, di = %d\n", curD, di);
			for (int i = 0; i < r; i++)
				eprintf("%s\n", f[i] );
			throw;
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	{
		int curD = bfs(sx, sy, tx, ty, false, -1, -1);
		if (curD != di) 
			throw;
	}
	printf("POSSIBLE\n");
	for (int i = 0; i < r; i++)
		printf("%s\n", f[i] );
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


