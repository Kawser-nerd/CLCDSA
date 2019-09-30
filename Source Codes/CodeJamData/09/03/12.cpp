//	GCJ 2009 Qual (C)

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

const int MO = 10000;

const int M = 19;
char WEL[] = "welcome to code jam";

char buf[100010];
int L;
int dp[30];

int main() {
	int i, j;
	
	for (int TC = atoi(gets(buf)), tc = 0; TC--; ) {
		L = strlen(gets(buf));
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (i = 0; i < L; ++i) {
			for (j = M; j--; ) {
				if (buf[i] == WEL[j]) {
					(dp[j + 1] += dp[j]) %= MO;
				}
			}
		}
		printf("Case #%d: %04d\n", ++tc, dp[M]);
	}
	
	
	return 0;
}

