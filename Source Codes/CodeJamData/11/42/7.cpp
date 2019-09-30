#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, m;
int64 d0;
int64 d[501][501], x[501][501], y[501][501];
int64 sumd[501][501], sumx[501][501], sumy[501][501];

void calccalc () {
	seta (d, 0);
	scanf ("%d%d%I64d", &n, &m, &d0);
	forn (i, n)
		forn (j, m) {
			char c;
			scanf (" %c", &c);
			d[i+1][j+1] = d0 + c - '0';
		}
	seta (x, 0);
	seta (y, 0);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			x[i][j] = i * 2 * d[i][j];
			y[i][j] = j * 2 * d[i][j];
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			sumx[i][j] = sumx[i-1][j] + sumx[i][j-1] - sumx[i-1][j-1] + x[i][j];
			sumy[i][j] = sumy[i-1][j] + sumy[i][j-1] - sumy[i-1][j-1] + y[i][j];
			sumd[i][j] = sumd[i-1][j] + sumd[i][j-1] - sumd[i-1][j-1] + d[i][j];			
		}
	for (int k = min (n, m); k >= 3; k --) {
		for (int lx = 1; lx + k - 1 <= n; lx ++)
			for (int ly = 1; ly + k - 1 <= m; ly ++) {
				int rx = lx + k - 1;
				int ry = ly + k - 1;
				int64 SUMD = sumd[rx][ry] - sumd[lx-1][ry] - sumd[rx][ly-1] + sumd[lx-1][ly-1];
				int64 SUMX = sumx[rx][ry] - sumx[lx-1][ry] - sumx[rx][ly-1] + sumx[lx-1][ly-1];
				int64 SUMY = sumy[rx][ry] - sumy[lx-1][ry] - sumy[rx][ly-1] + sumy[lx-1][ly-1];
				SUMD -= d[rx][ry] + d[lx][ry] + d[rx][ly] + d[lx][ly];
				SUMX -= x[rx][ry] + x[lx][ry] + x[rx][ly] + x[lx][ly];
				SUMY -= y[rx][ry] + y[lx][ry] + y[rx][ly] + y[lx][ly];
				int64 px = rx + lx;
				int64 py = ry + ly;
				if (px * SUMD == SUMX && py * SUMD == SUMY) {
					cout << k << endl;
					return;
				}
			}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn (ii, tt) {
		printf ("Case #%d: ", ii+1);
		calccalc ();
	}
	return 0;
}
