//	GCJ 2009 World FInals (D)
//	Author: hos.lyric

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; while ((c = getchar()) <= ' ') { if (!~c) throw ~0; } return c; }
int in() {
	int x = 0, c;
	while ((uint)((c = getchar()) - '0') >= 10) { if (c == '-') return -in(); if (!~c) throw ~0; }
	do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
	return x;
}

inline int sq(int x) { return x * x; }

#define MAXN 510
#define MAXM 300010

int n, m;
int ptr0[MAXN], next0[MAXM], zu0[MAXM];
int ptr1[MAXN], next1[MAXM], zu1[MAXM];

inline void init(int _n) {
	n = _n;
	memset(ptr0, ~0, n << 2);
	memset(ptr1, ~0, n << 2);
	m = 0;
}
inline void ae(int u, int v) {
	next0[m] = ptr0[u]; ptr0[u] = m; zu0[m] = v;
	next1[m] = ptr1[v]; ptr1[v] = m; zu1[m] = u;
	++m;
}

//	Strongly Connected Component
int scc[MAXN], stac[MAXN], *st;
void sccdfs0(int u) {
	scc[u] = ~0;
	for (int i = ptr0[u]; ~i; i = next0[i]) if (!scc[zu0[i]]) sccdfs0(zu0[i]);
	*st++ = u;
}
void sccdfs1(int u, int cm) {
	scc[u] = cm;
	for (int i = ptr1[u]; ~i; i = next1[i]) if (!~scc[zu1[i]]) sccdfs1(zu1[i], cm);
}
int sccgo() {
	int u, cm;
	st = stac;
	memset(scc, 0, n << 2);
	for (u = 0; u < n; ++u) if (!scc[u]) sccdfs0(u);
	for (cm = 0; st-- != stac; ) if (!~scc[*st]) sccdfs1(*st, cm++);
	return cm;
}

int N;
int X[MAXN], Y[MAXN], R[MAXN], S[MAXN];

int is[MAXN][MAXN], ie[MAXN][MAXN];
int C;
int val[MAXN];
int sum[40010], grp[MAXN];

int main() {
	int h, i, j, k;
	int u, v;
	
	for (int TC = in(), tc = 0; TC--; ) {
		N = in();
		for (u = 0; u < N; ++u) {
			X[u] = in();
			Y[u] = in();
			R[u] = in();
			S[u] = in();
		}
		memset(is, 0, sizeof(is));
		memset(ie, 0, sizeof(ie));
		init(N);
		for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) if (u != v) {
			if (sq(X[v] - X[u]) + sq(Y[v] - Y[u]) <= R[u] * R[u]) {
				is[u][v] = 1;
				ae(u, v);
			}
		}
		C = sccgo();
//pv(scc,scc+N);
		for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
			if (is[u][v] && scc[u] != scc[v]) {
				ie[scc[u]][scc[v]] = 1;
			}
		}
		memset(val, 0, sizeof(val));
		for (u = 0; u < N; ++u) val[scc[u]] += S[u];
		
		//	for N <= 15
		for (i = 0; i < C; ++i) sum[1 << i] = val[i];
		for (h = 0; h < 1 << C; ++h) sum[h] = sum[h & h - 1] + sum[h & -h];
//pv(val,val+C);pv(sum,sum+(1<<C));
		for (k = 0; k < C; ++k) for (i = 0; i < C; ++i) for (j = 0; j < C; ++j) {
			ie[i][j] |= ie[i][k] & ie[k][j];
		}
		memset(grp, 0, sizeof(grp));
		for (i = 0; i < C; ++i) for (j = 0; j < C; ++j) {
			if (i == j || ie[i][j]) grp[i] |= 1 << j;
		}
		int ans = 0, tmp, grs;
		for (h = 0; h < 1 << C; ++h) {
			grs = 0;
			for (i = 0; i < C; ++i) if (h & 1 << i) grs |= grp[i];
			tmp = sum[grs];
			if (ans < tmp) ans = tmp;
		}
		printf("Case #%d: %d\n", ++tc, ans);
		
	}
	
	
	return 0;
}

