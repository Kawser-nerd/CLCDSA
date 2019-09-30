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

const int mod = 10009;

char buf[1<<20];
vector<string> words;

vector<int> solve(string expr, int k) {
	int n = size(expr);
	vector<vector<int> > dp(k+1, vector<int>(1<<n));

	FOR(i, 1, k) REP(w, size(words)) {
		int a[4] = {};
		{
		REP(j, size(words[w])) REP(k, n)
			if (words[w][j] == expr[k])
				++a[k];
		}
		REP(mask, 1<<n) {
			if (i == 1) {
				int p = 1;
				REP(j, n)
					if (mask&(1<<j))
						p = p*a[j]%mod;
				dp[i][mask] = (dp[i][mask]+p)%mod;
			} else {
				REP(subMask, 1<<n) if ((subMask&mask) == subMask) {
					int p = dp[i-1][subMask];
					{
					REP(j, n)
						if ((mask&(1<<j)) && !(subMask&(1<<j)))
							p = p*a[j]%mod;
					}
					dp[i][mask] = (dp[i][mask]+p)%mod;
				}
			}
		}
	}

	vector<int> res(k+1);
	FOR(i, 1, k)
		res[i] = dp[i][(1<<n)-1];
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int ntests;
	scanf("%d", &ntests);
	FOR(test, 1, ntests) {
		printf("Case #%d:", test);
		scanf("%s", buf);
		string expr(buf);
		int k;		
		scanf("%d", &k);
		int n;
		scanf("%d", &n);
		words.resize(n);
		REP(i, n) {
			scanf("%s", buf);
			words[i] = buf;
		}
		vector<int> ans(k+1);
		expr += '+';
		int i = 0;
		while (i < size(expr)) {
			string s;
			while (expr[i] != '+')
				s += expr[i++];
			++i;
			vector<int> add = solve(s, k);
			FOR(i, 0, k) ans[i] = (ans[i]+add[i])%mod;
		}
		FOR(i, 1, k) printf(" %d", ans[i]);
		printf("\n");
		fflush(stdout);
	}

	exit(0);
}
