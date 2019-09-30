//	GCJ 2009 Round 2 (A)

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

int N;
char S[50][50];
int A[50];
bool us[50];
int is[50];

int main() {
	int i, j;
	
	for (int TC = in(), tc = 0; TC--; ) {
		N = in();
		for (i = 0; i < N; ++i) {
			scanf("%s", S[i]);
		}
		for (i = 0; i < N; ++i) {
			A[i] = -1;
			for (j = 0; j < N; ++j) {
				if (S[i][j] == '1') A[i] = j;
			}
		}
//pv(A,A+N);
		
		memset(us, 0, sizeof(us));
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (!us[j] && A[j] <= i) break;
			}
			us[j] = 1;
			is[i] = j;
		}
//pv(is,is+N);
		
		int ans = 0;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N - 1; ++j) {
				if (is[j] > is[j + 1]) {
					swap(is[j], is[j + 1]);
					++ans;
				}
			}
		}
		
		printf("Case #%d: %d\n", ++tc, ans);
		
	}
	
	
	return 0;
}

