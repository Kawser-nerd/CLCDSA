#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <functional>
using namespace std;

typedef long long int64;
#define PB push_back
#define MP make_pair
#define debug(x) cout<<(#x)<<": "<<(x)<<endl
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define MOD 1000000007

int n, m, k;

inline int area(int a, int b, int r) {
	int ret = 0;
	REP(i, r) ret += min(m, min(a+i+i, b+(r-1-i)+(r-1-i)));
	return ret;
}

int main() {
	int tN;
	cin >> tN;
	FOR(cN, 1, tN) {
		cin >> n >> m >> k;
		if (n < m) swap(n, m);
		int ans = n+n+m+m;
		if (k <= n) ans = k;
		// first line a stones, last line b stones
		if (m > 1) {
			FOR(a, 1, m)
			FOR(b, a, m) {
				int L = 1, R = n;
				while (L + 1 < R) {
					int M = (L + R) / 2;
					if (area(a, b, M) >= k) R = M; else L = M;
				}
				if (area(a, b, R) >= k) ans = min(ans, a+b+2*(R-2));
			}
		}
		cerr << cN << endl;
		printf("Case #%d: %d\n", cN, ans);
	}
}
