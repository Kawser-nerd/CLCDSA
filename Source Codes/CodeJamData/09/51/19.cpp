//	GCJ 2009 Round 3 (A)

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

#define _(x,y) ((x) << 4 | (y))
#define xof(z) ((z) >> 4)
#define yof(z) ((z) & 0xf)

int dx[] = {1, 0, -1, 0, };
int dy[] = {0, 1, 0, -1, };

int K;
int M, N;
char S[20][20];
vint START, GOAL;

struct UnionFind : vint {
	UnionFind(int n) { assign(n, -1); }
	int root(int x) { return (at(x) < 0) ? x : (at(x) = root(at(x))); }
	bool conn(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return 0;
		if (at(x) > at(y)) std::swap(x, y);
		at(x) += at(y); at(y) = x;
		return 1;
	}
};
bool con(vint &u) {
	UnionFind uf(K);
	for (int i = 0; i < K; ++i) for (int j = i + 1; j < K; ++j) {
		if (abs(xof(u[i]) - xof(u[j])) + abs(yof(u[i]) - yof(u[j])) == 1) uf.conn(i, j);
	}
	return (-uf[0] == K);
}

int main() {
	int h, i, j;
	int x, y, xx, yy, zz, xxx, yyy, zzz;
	vint u, v;
	int c;
	bool uc;
	
	for (int TC = in(), tc = 0; TC--; ) {
		printf("Case #%d: ", ++tc);
		M = in();
		N = in();
		for (x = 1; x <= M; ++x) {
			scanf("%s", S[x] + 1);
		}
		
		for (x = 0; x <= M + 1; ++x) S[x][0] = S[x][N + 1] = '#';
		for (y = 0; y <= N + 1; ++y) S[0][y] = S[M + 1][y] = '#';
		
		START.clear();
		GOAL.clear();
		
		for (x = 1; x <= M; ++x) for (y = 1; y <= N; ++y) {
			if (S[x][y] == 'o') START.push_back(_(x, y));
			if (S[x][y] == 'x') GOAL.push_back(_(x, y));
			if (S[x][y] == 'w') START.push_back(_(x, y)), GOAL.push_back(_(x, y));
		}
		
		K = START.size();
		sort(START.begin(), START.end());
		sort(GOAL.begin(), GOAL.end());
		
		queue<vint> q;
		map<vint,int> d;
		
		d[START] = 0;
		q.push(START);
		
		for (; !q.empty(); ) {
//pv(u.begin(),u.end());
			u = q.front();
			q.pop();
			c = d[u];
			if (u == GOAL) {
				printf("%d\n", c);
				goto found;
			}
			uc = con(u);
			for (i = 0; i < K; ++i) {
				x = xof(u[i]); y = yof(u[i]);
				for (h = 0; h < 4; ++h) {
					xx = x + dx[h]; yy = y + dy[h]; zz = _(xx, yy);
					xxx = x - dx[h]; yyy = y - dy[h]; zzz = _(xxx, yyy);
					if (S[xx][yy] == '#') goto cont;
					if (S[xxx][yyy] == '#') goto cont;
					for (j = 0; j < K; ++j) if (u[j] == zz) goto cont;
					for (j = 0; j < K; ++j) if (u[j] == zzz) goto cont;
					v = u;
					v[i] = zz;
					sort(v.begin(), v.end());
					if (!uc && !con(v)) goto cont;
					if (!d.count(v)) {
						d[v] = c + 1;
						q.push(v);
					}
				cont:;
				}
			}
		}
		
		puts("-1");
	found:;
		
	}
	
	
	return 0;
}

