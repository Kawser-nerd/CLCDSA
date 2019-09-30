//	GCJ 2009 Qual (A)

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

char buf[100010];

int L, D;
char S[5010][20];
int pat[20][30];

int main() {
	int TC;
	int i, j, k;
	int ans;
	
	L = in();
	D = in();
	TC = in();
	
	for (i = 0; i < D; ++i) {
		scanf("%s", S[i]);
	}
	
	for (int tc = 0; TC--; ) {
		scanf("%s", buf);
		memset(pat, 0, sizeof(pat));
		for (k = 0, j = 0; j < L; ++j, ++k) {
			if (buf[k] == '(') {
				for (++k; buf[k] != ')'; ++k) {
					pat[j][buf[k] - 'a'] = 1;
				}
			} else {
				pat[j][buf[k] - 'a'] = 1;
			}
		}
		ans = 0;
		for (i = 0; i < D; ++i) {
			for (j = 0; j < L; ++j) {
				if (!pat[j][S[i][j] - 'a']) break;
			}
			if (j == L) ++ans;
		}
		printf("Case #%d: %d\n", ++tc, ans);
	}
	
	
	return 0;
}

