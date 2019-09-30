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

int64 gcd(int64 a, int64 b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int tN;
	cin >> tN;
	FOR(cN, 1, tN) {
		string s;
		cin >> s;
		REP(i, s.size()) if (s[i] == '/') s[i] = ' ';
		istringstream iss(s);
		int64 P, Q;
		iss >> P >> Q;
		int64 g = gcd(P, Q);
		P /= g; Q /= g;
		bool ok = 0;
		FOR(k, 1, 40) if (Q == (1LL << k)) ok = 1;
		printf("Case #%d: ", cN);
		if (!ok) puts("impossible");
		else {
			int ans;
			FOR(k, 1, 40) {
				if (Q % (1LL << k) > 0) break;
				if (P >= Q / (1LL << k)) {ans = k; break;}
			}
			printf("%d\n", ans);
		}
	}
}
