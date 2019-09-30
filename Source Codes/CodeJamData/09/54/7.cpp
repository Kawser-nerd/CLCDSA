//	GCJ 2009 Round 3 (D)

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

const Int MO = 1000000007;
const Int LIM = 10000000000000LL;

int M;
Int ps[20000010], ds[20000010];

char bufa[1010], bufb[1010];

Int count(Int n) {	//	good, <= n
	int i = upper_bound(ps, ps + M, n) - ps;
	if (i & 1) return ds[i];
	return ds[i] - (ps[i] - n - 1);
}

int main() {
	int k, a;
	int len;
	
	M = 1;
	for (k = 1; ; k *= 10) {
		for (a = k; a < k * 10; ++a) {
			len = sprintf(bufa, "%d", a);
			reverse(bufa, bufa + len);
			sprintf(bufb, "%d%s", a, bufa + 1);
			sscanf(bufb, "%lld", &ps[M++]);
		}
		if (k == 1000000) break;
		for (a = k; a < k * 10; ++a) {
			len = sprintf(bufa, "%d", a);
			reverse(bufa, bufa + len);
			sprintf(bufb, "%d%s", a, bufa);
			sscanf(bufb, "%lld", &ps[M++]);
		}
	}
	
	ps[M++] = LIM + 1;
	for (a = 1; a < M; ++a) {
		ds[a] = ds[a - 1] + ((a & 1) ? 0 : ps[a] - ps[a - 1]);
	}
	
//pv(ps,ps+100);pv(ds,ds+100);
//pv(ps+M-15,ps+M);pv(ds+M-15,ds+M);
	for (int TC = in(), tc = 0; TC--; ) {
		Int L, R;
		scanf("%lld%lld", &L, &R);
		
//cout<<R<<" "<<count(R)<<endl;
//cout<<L-2<<" "<<count(L-2)<<endl;
		Int x = count(R) - count(L - 2);
		Int y = R - L + 2 - x;
//cout<<x<<" "<<y<<endl;
		x %= MO;
		y %= MO;
		
		printf("Case #%d: %lld\n", ++tc, (x * (x - 1) / 2 + y * (y - 1) / 2) % MO);
		
	}
	
	
	return 0;
}

