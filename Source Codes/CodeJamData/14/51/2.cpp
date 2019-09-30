#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1000010
//#define INF 1000000000000000000LL
int n, a[N];
ll t[N];

void gen() {
	ll p,q,r,s;
	cin >> n >> p >> q >> r >> s;
	for (int i = 0; i < n; i ++) 
		a[i] = ((ll)i*p+q)%r+s;
}

int main()
{
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		gen();
		for (int i = 0; i < n; i ++) 
			t[i+1] = t[i] + a[i];
		int l = 0, r = n-1; 
		ll S = 0;
		while (l < r) {
			S = max(S, t[n]-max(max(t[l],t[n]-t[r+1]),t[r+1]-t[l]));
			if (t[l+1] < t[n] - t[r]) l ++; else r --;
		}
		S = max(S, t[n]-max(max(t[l],t[n]-t[r+1]),t[r+1]-t[l]));
		printf ("Case #%d: %.18lf\n", __, (double)S/t[n]); 
	}
	return 0;
}