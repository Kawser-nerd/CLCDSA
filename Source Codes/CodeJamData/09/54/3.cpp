#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>
using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int64;
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return (int)c.size(); }
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }

bool isPalindrome(int64 x) {
	char buf[32];
	sprintf(buf, "%lld", x);
	for (int i = 0, j = int(strlen(buf))-1; i < j; ++i, --j)
		if (buf[i] != buf[j])
			return false;
	return true;
}

const int mod = 1000000007;

int64 f(int64 n) {
	return n*(n+1)/2;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int ntests;
	scanf("%d", &ntests);
	FOR(test, 1, ntests) {
		printf("Case #%d: ", test);
		int64 L, R;
		scanf("%I64d%I64d", &L, &R);
		vector<int64> palin;
		for (int i = 1; true; ++i) {
			char buf[32];
			sprintf(buf, "%d", i);
			int len = strlen(buf);
			int64 k = 0;
			REP(j, len)
				k = k*10+buf[j]-'0';
			REPD(j, len-1)
				k = k*10+buf[j]-'0';
			if (k > R) break;
			if (k >= L) palin.push_back(k);
			k = 0;
			REP(j, len)
				k = k*10+buf[j]-'0';
			REPD(j, len)
				k = k*10+buf[j]-'0';
			if (k >= L && k <= R) palin.push_back(k);
		}
		sort(ALL(palin));
		palin.push_back(R+1);
		int64 odd = 0, even = 0;
		int64 res = 0;
		REPD(i, size(palin)-1) {
			res = (res+(palin[i+1]-palin[i]-1)*even)%mod;
			res = (res+f(palin[i+1]-palin[i]-1))%mod;
			even = (even+palin[i+1]-palin[i]-1)%mod;
			res = (res+odd)%mod;
			swap(odd, even);
			odd = (odd+1)%mod;
		}

		/*REP(i, size(palin)-1)
			assert(palin[i] >= L && palin[i] <= R && palin[i] < palin[i+1]);
		int64 cur = 0;
		FOR(f, palin[0], R) {
			int64 cnt = 0;
			FOR(s, f, R) {
				if (isPalindrome(s)) ++cnt;
				if (cnt%2 == 0) ++cur;
			}
		}*/

		res = (res+(palin[0]-L)*even)%mod;
		res = (res+f(palin[0]-L))%mod;

		printf("%lld\n", res);
		fflush(stdout);
	}

	exit(0);
}
