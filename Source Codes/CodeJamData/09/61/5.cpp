//	GCJ 2009 World Finals (A)
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

Int N;
int T;
int M[60], D[60][60];
set<int> used;

int main() {
	int i, j;
	int a, b;
	int c, d;
	
	for (int TC = in(), tc = 0; TC--; ) {
		N = in();
		T = in();
		for (i = 0; i < T; ++i) {
			M[i] = in();
			for (j = 1; j < M[i]; ++j) {
				D[i][j] = in() - 1;
			}
		}
		//	for T == 2
		assert(T == 2);
		Int P = 0, Q = N * N;
		Int oth = Q;
		for (a = 0; a < M[0]; ++a) for (b = 0; b < M[1]; ++b) {
			int dly = D[1][b] - D[0][a];
			if (!used.count(dly)) continue;
			used.insert(dly);
			int tmp = 0;
			for (c = 0; c < M[0]; ++c) for (d = 0; d < M[1]; ++d) {
				if (D[0][c] + dly == D[0][d]) {
					
				}
			}
		}
		
	}
	
	
	return 0;
}

