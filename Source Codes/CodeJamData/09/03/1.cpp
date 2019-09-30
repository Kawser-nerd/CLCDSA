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

const string target = "welcome to code jam";

char buf[1<<20];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	gets(buf);
	FOR(test, 1, atoi(buf)) {
		gets(buf);
		string s(buf);
		int n = size(s);
		int k = size(target);
		vector<vector<int> > dp(n+1, vector<int>(k+1));
		dp[0][0] = 1;
		const int mod = 10000;
		assert(k == 19);
		REP(i, n) REP(j, k+1) {
			dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
			if (j < k && s[i] == target[j])
				dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
		}
		printf("Case #%d: %04d\n", test, dp[n][k]);
	}

	exit(0);
}
