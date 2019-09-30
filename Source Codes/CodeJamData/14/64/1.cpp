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

#define N 100

int n, k;
string A[N];
bitset<N> K[N],L[N];

// K x y := x kills y
// L x y := x loses y

bitset<N> R;
bitset<N> all;

bool can(int la) {
	if (R[k]) {
		return ((all^R)&L[k]).count() == 0;
	}

	bitset<N> w;
	w = all^R;
	w[k] = 0;
	
	bitset<N> g;
	g[k] = 1;
	
	while (true) {
		bitset<N> u; u.reset();
		for (int i = 0; i < n; i ++)
			if (g[i]) u |= K[i];
		bitset<N> v = u&w;
		if (v.count() == 0) break;
		g |= v;
		w &= (all^v);
	}
	bool laWin = 0;
	if (w.count() == 0) laWin = 1;
	if (la != -1) {
		if ((K[la] & w).count() == w.count()) laWin = 1;
	}
	bool laGood = 0;
	if (la == -1) {
		laGood = 1;
	} else {
		if ((int)(L[k] & g).count() != 0) 
			laGood = 1;
	}
	return laWin && laGood;
}

int main()
{
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> k;
		for (int i = 0; i < n; i ++) {
			K[i].reset(); 
			L[i].reset();
		}
		for (int i = 0; i < n; i ++) {
			cin >> A[i];
			for (int j = 0; j < n; j ++)
				if (A[i][j] == 'Y') {
					K[i][j] = 1;
					L[j][i] = 1;
				} else {
					K[j][i] = 1;
					L[i][j] = 1;
				}
		}
		R.reset();
		all.reset();
		for (int i = 0; i < n; i ++) all[i] = 1;
		printf ("Case #%d: ",__);
		int la = -1;
		if (!can(la)) {
			puts ("IMPOSSIBLE");
			continue;
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) if (!R[j]) {
				if (la != -1 && j == k) 
					if (K[la][j]) continue;
				R[j] = 1;
				int nla = la;
				if (nla == -1) nla = j; else
				if (K[j][nla]) nla = j;
				if (can(nla)) {
					la = nla;
					printf("%d%c",j,i==n-1?'\n':' ');
					break;
				}
				R[j] = 0;
			}
		}
	}
	return 0;
}
