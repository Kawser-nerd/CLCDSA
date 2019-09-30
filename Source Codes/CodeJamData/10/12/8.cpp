//	GCJ 2010 Round 1A (B)

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

const int INF = 1001001001;
const int L = 256;

int D, E, M, N;
int A[310];
int ume[310][310];
int dp[310][310];

int main() {
	int i, j, k;
	
	for (int TC = in(), tc = 0; ++tc <= TC; ) {
		D = in();
		E = in();
		M = in();
		N = in();
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		for (j = 0; j < L; ++j) for (k = 0; k < L; ++k) {
			ume[j][k] = M ? ((abs(j - k) + M - 1) / M * E) : (j != k) ? INF : 0;
		}
		memset(dp, 0x3f, sizeof(dp));
		for (j = 0; j < L; ++j) {
			dp[0][j] = 0;
		}
		for (i = 0; i < N; ++i) {
			//	process cell i
			for (j = 0; j < L; ++j) {
				//	using
				for (k = 0; k < L; ++k) if (abs(j - k) <= M) {
					chmin(dp[i << 1 | 1][k], dp[i << 1][j] + abs(A[i] - k));
				}
				//	deleting
				chmin(dp[i << 1 | 1][j], dp[i << 1][j] + D);
			}
			//	process betw i and i + 1
			for (j = 0; j < L; ++j) {
				for (k = 0; k < L; ++k) {
					chmin(dp[i + 1 << 1][k], dp[i << 1 | 1][j] + ume[j][k]);
				}
			}
		}
//for(i=0;i<=N<<1;++i)pv(dp[i],dp[i]+L);
		int ans = *min_element(dp[N << 1], dp[N << 1] + L);
		printf("Case #%d: %d\n", tc, ans);
	}
	
	return 0;
}

