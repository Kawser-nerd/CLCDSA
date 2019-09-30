//	GCJ 2009 Round 2 (C)

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

namespace BM {
	#define MAXN1 110
	#define MAXN2 110
	#define MAXM  10010
	int n1, n2, m, ptr[MAXN1], next[MAXM], zu[MAXM];
	int to[MAXN1], fr[MAXN2], us[MAXN2], ze;
	inline void init(int _n1, int _n2) {
		n1 = _n1; n2 = _n2; m = 0; memset(ptr, ~0, n1 << 2);
	}
	inline void ae(int u, int v) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
	}
	int augment(int u) {
		int i, v;
		for (i = ptr[u]; ~i; i = next[i]) if (us[v = zu[i]] != ze) {
			us[v] = ze;
			if (!~fr[v] || augment(fr[v])) {
				to[u] = v; fr[v] = u; return 1;
			}
		}
		return 0;
	}
	int fof() {
		memset(to, ~0, n1 << 2); memset(fr, ~0, n2 << 2); memset(us, ~0, n2 << 2);
		int ret = 0;
		for (ze = 0; ze < n1; ++ze) ret += augment(ze);
		return ret;
	}
}

int N, K;
int A[110][110];

int main() {
	using namespace BM;
	
	int i, u, v;
	
	for (int TC = in(), tc = 0; TC--; ) {
		N = in();
		K = in();
		for (u = 0; u < N; ++u) {
			for (i = 0; i < K; ++i) {
				A[u][i] = in();
			}
		}
		
		init(N, N);
		for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
			for (i = 0; i < K; ++i) {
				if (A[u][i] >= A[v][i]) break;
			}
			if (i == K) ae(u, v);
		}
		
		printf("Case #%d: %d\n", ++tc, N - fof());
		
	}
	
	
	return 0;
}

