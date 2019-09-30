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
bool a[400][400];
int d[400];
int q[400];
int t[400][400];
int H;

void bfs () {
	seta (q, 255);
	seta (d, 1);
	d[0] = 0;
	int h, t;
	h = t = 0;
	q[h] = 0;
	while (h <= t) {
		int v = q[h];
		h ++;
		forn (i, n)
			if (a[v][i] && d[i] > d[v] + 1) {
				d[i] = d[v] + 1;
				t ++;
				q[t] = i;
			}
	}
	H = h;
	cout << d[1]-1 << " ";
}

void calccalc () {
	seta (a, 0);
	scanf ("%d%d", &n, &m);
	forn (i, m) {
		int x, y;
		scanf ("%d,%d", &x, &y);
		a[x][y] = a[y][x] = 1;
	}	
	bfs ();
	int res = 0;
	if (d[1] == 1) {
		forn (i, n)
			if (a[0][i] == 1)
				res ++;
		cout << res << endl;
		return;
	}
	if (d[1] == 2) {
		forn (i, n)
			if (d[i] == 1 && a[i][1]) {
				int tmpres = 0;
				forn (j, n)
					if (j != 0 && j != i && (a[0][j] || a[i][j]))
						tmpres ++;
				res = max (res, tmpres);
			}
		cout << res << endl;
		return;
	}
	seta (t, 255);
	forn (i, H)
		forn (j, H)
			if (d[q[i]] == 1 && d[q[j]] == 2 && a[q[i]][q[j]]) {
			        t[q[i]][q[j]] = 0;
				forn (k, n)
					if (q[i] != k && q[j] != k && 0 != k && (a[0][k] || a[q[i]][k] || a[q[j]][k]))
						t[q[i]][q[j]] ++;
			}
	forn (i, H)
		forn (j, H)
			if (t[q[i]][q[j]] >= 0) {
				if (d[q[j]] == d[1]-1) {
					if (a[q[j]][1])
						res = max (res, t[q[i]][q[j]]);
				}
				else {
					forn (k, H) 
						if (d[q[k]] == d[q[j]] + 1 && a[q[k]][q[j]]) {
							int tmpres = t[q[i]][q[j]] - 1;
							forn (l, n)
								if (a[q[k]][l] && (!a[q[i]][l]) && (!a[q[j]][l]))
									tmpres ++;
							t[q[j]][q[k]] = max (t[q[j]][q[k]], tmpres);
						}
				}
			}
	cout << res << endl;
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
