//	GCJ 2009 World FInals (E)
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

const int INF = 1001001001;

int N, NN;
map<string,int> num;
int A[50];
int L, M;
int P[50], Q[50];

int p1[30], p2[30];

int calc(int a[], int lef, int rig) {
	if (lef > rig) return 0;
	int pos = p2[a[lef]];
	if (pos <= lef || rig < pos) return INF;
	return max(calc(a, lef + 1, pos - 1) + 1, calc(a, pos + 1, rig));
}
int solve(int nn, int a[]) {
	int i;
	memset(p1, ~0, sizeof(p1));
	memset(p1, ~0, sizeof(p2));
	for (i = 0; i < nn; ++i) {
		(~p1[a[i]]) ? p2[a[i]] = i : p1[a[i]] = i; 
	}
	return calc(a, 0, nn - 1);
}

int main() {
	int h, i;
	string str;
	
	for (int TC = in(), tc = 0; TC--; ) {
		N = in();
		NN = N << 1;
		num.clear();
		int cnt = 0;
		for (i = 0; i < NN; ++i) {
			cin >> str;
			if (!num.count(str)) num[str] = cnt++;
			A[i] = num[str];
		}
//pv(A,A+NN);
		
		int ans = INF, tmp;
		
		for (h = 0; h < 1 << N; ++h) {
			L = M = 0;
			for (i = 0; i < NN; ++i) {
				if (h & 1 << A[i]) {
					P[L++] = A[i];
				} else {
					Q[M++] = A[i];
				}
			}
			tmp = solve(L, P) + solve(M, Q);
			if (ans > tmp) ans = tmp;
		}
		
		if (ans == INF) ans = -1;
		printf("Case #%d: %d\n", ++tc, ans);
		
	}
	
	
	return 0;
}

