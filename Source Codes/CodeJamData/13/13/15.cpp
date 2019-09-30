#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
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
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int NMAX = 18564;
const int MMAX = 5915;

int n, m, k, r, N;
map<int64, int> M;
vector<string> a;
int64 S[NMAX];
int64 g[MMAX][NMAX];
double u[NMAX];
int64 C[20][20];

string t;
int64 ww;

void go(int v, int l, int64 cur) {
	if (v == n) {
		ww += cur;
		S[a.size()] = cur;
		a.pb(t);
		return;
	}
	if (l > m) return;
	string w = t;
	for (int i = 0; i + v <= n; i++) {
		go(v+i, l+1, cur * C[v+i][i]);
		t += (char)(l + '0');
	}
	t = w;
}

void solve_case() {
	seta(u, 0);
	forn(i, a.size())
		u[i] = S[i];
	forn(i, k) {
		int64 x;
		cin >> x;
		int v = M[x];
		forn(j, a.size())
			u[j] *= (double)g[v][j];
	}
	int best = 0;
	forn(i, a.size())
		if (u[best] < u[i])
			best = i;
	cerr << u[best] << endl;
	cout << a[best] << endl;				
}

void solve() {
	cin >> r >> n >> m >> k;
	M.clear();
	t = "";
	seta(g, 0);
	go(0, 2, 1);
	N = 0;
	forn(i, a.size()) {
		forn(j, 1 << n) {
			int64 cur = 1;
			forn(k, n)
				if (j & (1 << k))
					cur = cur * (a[i][k] - '0');		
			if (!M.count(cur)) {
				M[cur] = N;
				N++;
			}
			int v = M[cur];
			g[v][i] ++;
		}
	}
	cerr << a.size() << " " << M.size() << endl;
	cerr << clock() << endl;
	forn(i, r) {
		solve_case();	
	}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta(C, 0);
	forn(i, 20)
		C[i][0] = 1;
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d:\n", ii+1);
		solve();
	}
	cerr << clock() << endl;
	return 0;
}
