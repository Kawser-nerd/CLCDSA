//	GCJ 2009 World Finals (B)
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

const double INF = 1e10;
double sq(double x) { return x * x; }

const int LMAX = 100;

int N, L;
double X[10010], Y[10010];
double D[10010][10010];
pair<double,int> P[10010];

int main() {
	int i, j, k;
	
	for (int TC = in(), tc = 0; TC--; ) {
		N = in();
		for (i = 0; i < N; ++i) {
			X[i] = in();
			Y[i] = in();
		}
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) {
			if (i > j) {
				D[i][j] = D[j][i];
			} else {
				D[i][j] = sqrt(sq(X[j] - X[i]) + sq(Y[j] - Y[i]));
			}
		}
//for(i=0;i<N;++i)pv(D[i],D[i]+N);
		double ans = INF, tmp;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < i; ++j) {
				P[j] = mp(D[i][j], j);
			}
			L = min(i, LMAX);
			partial_sort(P, P + L, P + i);
			for (j = 0; j < L; ++j) for (k = 0; k < j; ++k) {
				tmp = P[j].first + P[k].first + D[P[j].second][P[k].second];
				if (ans > tmp) ans = tmp;
			}
		}
		printf("Case #%d: %.8f\n", ++tc, ans);
		
	}
	
	
	return 0;
}

