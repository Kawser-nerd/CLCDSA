//	GCJ 2010 Round 1A (C)

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

const double G = (1.0 + sqrt(5.0)) / 2.0;

Int A1, A2, B1, B2;

int main() {
	Int a;
	Int b1, b2;
	Int ans;
	
	for (int TC = in(), tc = 0; ++tc <= TC; ) {
		A1 = in();
		A2 = in();
		B1 = in();
		B2 = in();
		ans = (A2 - A1 + 1) * (B2 - B1 + 1);
		for (a = A1; a <= A2; ++a) {
			b1 = (Int)ceil(a / G);
			b2 = (Int)floor(a * G);
			if (b1 < B1) b1 = B1;
			if (b2 > B2) b2 = B2;
			if (b1 <= b2) ans -= b2 - b1 + 1;
		}
		printf("Case #%d: %lld\n", tc, ans);
	}
	
	return 0;
}

