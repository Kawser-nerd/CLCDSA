//	GCJ 2009 World Finals (C)
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

const int MO = 10007;

int M, N;
char S[20][20];
map< pair<int,pint>,int > mem;

int calc(int pos, int ue, int mae) {
//cout<<pos<<" "<<ue<<" "<<mae<<endl;
	if (pos == M * N) return 1;
	if (!mem.count(mp(pos, mp(ue, mae)))) {
		int ret = 0;
		int x = pos / N, y = pos % N;
		if (!y) mae = 'a';
		int u = ue >> (y * 8) & 0xff;
		int lim = max(u, mae);
		if (S[x][y] == '.') {
			for (int c = lim; c <= 'z'; ++c) {
				ret += calc(pos + 1, ue + ((c - u) << (y * 8)), c);
			}
			ret %= MO;
		} else {
			ret = (lim <= S[x][y]) ? calc(pos + 1, ue + ((S[x][y] - u) << (y * 8)), S[x][y]) : 0;
		}
		mem[mp(pos, mp(ue, mae))] = ret;
	}
	return mem[mp(pos, mp(ue, mae))];
}

int main() {
	int x, y;
	
	for (int TC = in(), tc = 0; TC--; ) {
		mem.clear();
		M = in();
		N = in();
		for (x = 0; x < M; ++x) {
			scanf("%s", S[x]);
		}
		int uef = 0;
		for (y = 0; y < N; ++y) {
			uef |= 'a' << (y * 8);
			}
		int res = calc(0, uef, 'a');
		printf("Case #%d: %d\n", ++tc, res);
	}
	
	
	return 0;
}

