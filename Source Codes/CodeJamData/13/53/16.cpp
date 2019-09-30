/*
    Author: Nikolay Kuznetsov
    Dedicated to my Love, Kristina Dmitrashko
*/
#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

struct edge {
	int v, u, l, r, id;

	edge(int v = 0, int u = 0, int l = 0, int r = 0, int id = 0) : v(v), u(u), l(l), r(r), id(id) {}

	int cost(int mask) {
		return bit(mask, id) ? l : r;
	}
};

int n, m, p, path[MAXN], d0[MAXN], d1[MAXN];
vector<edge> g[MAXN], gr[MAXN];
bool used[MAXN];
edge e[MAXN];

void dijkstra(int start, int * d, int mask, vector<edge> g[MAXN]) {
	forn(i, n) {
		used[i] = false;
		d[i] = INF;
	}

	d[start] = 0;
	while (true) {
		int v = -1, dist = INF;
		forn(i, n)
			if (!used[i] && d[i] < dist) {
				dist = d[i];
				v = i;
			}

		if (v == -1) break;
		used[v] = true;
		forn(i, g[v].size()) {
			int u = g[v][i].u;
			d[u] = min(d[u], d[v] + g[v][i].cost(mask));
		}
	}
}

int get(int mask) {
	dijkstra(0, d0, mask, g);
	dijkstra(1, d1, mask, gr);

	int D = d0[1], sum = 0;
	forn(i, p) {
		int id = path[i], v = e[id].v, u = e[id].u;
		sum += e[id].cost(mask);
		if (sum + d1[u] > D)
			return i;
	}

	return INF;
}

void solve(bool skip) {
	n = nextInt();
	m = nextInt();
	p = nextInt();
	forn(i, n) {
		gr[i].clear();
		g[i].clear();
	}

	forn(i, m) {
		int v = nextInt() - 1;
		int u = nextInt() - 1;
		int l = nextInt();
		int r = nextInt();
		e[i] = edge(v, u, l, r, i);
		g[v].pb(e[i]);
		gr[u].pb(edge(u, v, l, r, i));
	}

	forn(i, p)
		path[i] = nextInt() - 1;

	int ans = 0;
	forn(mask, 1 << m)
		ans = max(ans, get(mask));

	if (ans > INF/2)
		cout << "Looks Good To Me" << endl;
	else
		cout << path[ans] + 1 << endl;
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

	int L = 1, R = INF;
	if (argc >= 3) {
		L = atoi(argv[1]);
		R = atoi(argv[2]);
	}

	srand((unsigned int)time(0));
	int tests = nextInt();
	forn(test, tests) {
		time_t start = clock();
		cerr << "Case #" << test + 1 << endl;
		cout << "Case #" << test + 1 << ": ";
		solve(test < L-1 || test > R-1);
		cerr << "time is " << (0.0 + clock() - start) / CLOCKS_PER_SEC << endl;
	}

	return 0;
}
