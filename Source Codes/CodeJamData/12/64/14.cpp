#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int X[1 << 14];
int Y[1 << 14];
int DX[1 << 14][4];
int DY[1 << 14][4];

double dist(double x, double y){ return sqrt(x*x + y*y); }

double F(int n, int m)
{
	int i, j, k, l, z;
	double res = 0;
	FOR(i, 0, n)
		FOR(j, 0, n)
			FOR(k, 0, n)
				FOR(l, 0, n)
				{
					int I[] = {i, j, k, l};
					int x = 0;
					int y = 0;
					FOR(z, 0, 4)
					{
						int cnt = (m + 3 - z)/4;
						x += DX[ I[z] ][z]*cnt;
						y += DY[ I[z] ][z]*cnt;
					}

					res = max(res, dist(x, y));
				}

	return res;
}

int SolveTest(int test)
{
	int n, m;
	scanf("%d%d", &n, &m);

	int i, j;
	FOR(i, 0, n)
		scanf("%d%d", &X[i], &Y[i]);

	FOR(i, 0, n)
	{
		int dx = X[i] - Y[i];
		int dy = X[i] + Y[i];
		FOR(j, 0, 4)
		{
			DX[i][j] = dx;
			DY[i][j] = dy;

			swap(dx, dy);
			dy = -dy;
		}
	}

	double res = 0;
	FOR(i, 0, 4)
		if(i <= m)
			res = max(res, F(n, m - i));

	printf("Case #%d: %.7lf\n", test + 1, res);
	return 0;
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
