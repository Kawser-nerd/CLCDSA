//	GCJ 2010 Round 1A (A)

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
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
	int x = 0, c;
	for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
	do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
	return x;
}

int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1, };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1, };

int N, K;
char S[60][60];

bool search(char c) {
	int x, y, h, i;
	for (x = 1; x <= N; ++x) for (y = 1; y <= N; ++y) {
		for (h = 0; h < 8; ++h) {
			for (i = 0; i < K; ++i) {
				if (S[x + dx[h] * i][y + dy[h] * i] != c) break;
			}
			if (i == K) return 1;
		}
	}
	return 0;
}

int main() {
	int x, y;
	
	for (int TC = in(), tc = 0; ++tc <= TC; ) {
		N = in();
		K = in();
		memset(S, 0, sizeof(S));
		for (x = 1; x <= N; ++x) {
			scanf("%s", S[x] + 1);
		}
		for (x = 1; x <= N; ++x) {
			for (int reps = N; reps--; ) {
				for (y = N - 1; y >= 1; --y) {
					if (S[x][y + 1] == '.') swap(S[x][y], S[x][y + 1]);
				}
			}
		}
//for(x=1;x<=N;++x)cout<<S[x]+1<<endl;
		bool R = search('R'), B = search('B');
		printf("Case #%d: %s\n", tc, R ? (B ? "Both" : "Red") : (B ? "Blue" : "Neither"));
	}
	
	return 0;
}

