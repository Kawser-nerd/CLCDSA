//	GCJ 2009 Qual (B)

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

const int INF = 1001001001;

#define _(x,y) (((x) - 1) * W + ((y) - 1))

int N;
int uf[10010];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return 0;
	if (uf[x] > uf[y]) swap(x, y);
	uf[x] += uf[y]; uf[y] = x;
	return 1;
}

int H, W;
int A[110][110];
int is[10010], C;

int main() {
	int x, y, z, r;
	int tmp;
	
	for (int TC = in(), tc = 0; TC--; ) {
		H = in();
		W = in();
		for (x = 1; x <= H; ++x) for (y = 1; y <= W; ++y) {
			A[x][y] = in();
		}
		for (x = 0; x <= H + 1; ++x) A[x][0] = A[x][W + 1] = INF;
		for (y = 0; y <= W + 1; ++y) A[0][y] = A[H + 1][y] = INF;
		
		N = H * W;
		memset(uf, ~0, N << 2);
		for (x = 1; x <= H; ++x) for (y = 1; y <= W; ++y) {
			tmp = min(min(A[x - 1][y], A[x + 1][y]), min(A[x][y - 1], A[x][y + 1]));
			if (tmp < A[x][y]) {
				if (tmp == A[x - 1][y]) {	//	North
					conn(_(x, y), _(x - 1, y));
				} else if (tmp == A[x][y - 1]) {	//	West
					conn(_(x, y), _(x, y - 1));
				} else if (tmp == A[x][y + 1]) {	//	East
					conn(_(x, y), _(x, y + 1));
				} else {	//	South
					conn(_(x, y), _(x + 1, y));
				}
			}
		}
		
		printf("Case #%d:\n", ++tc);
		
		memset(is, 0, N << 2);
		C = 'a';
		for (z = 0; z < N; ++z) {
			r = root(z);
			if (!is[r]) is[r] = C++;
			putchar(is[r]);
			putchar(((z + 1) % W) ? ' ' : '\n');
		}
		
	}
	
	
	return 0;
}

