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

double C[41][41];

double getC(int n, int m) {
	static bool filled = false;
	if (!filled) {
		filled = true;
		FOR(i, 0, 40) FOR(j, 0, 40) 
			C[i][j] = j > i ? 0 : j == i || j == 0 ? 1 : C[i-1][j]+C[i-1][j-1];		
	}
	if (m < 0 || m > n) return 0;
	assert(0 <= n && n <= 40);
	return C[n][m];
}

int n, c;

double prob(int have, int add) {
	double res = getC(have, n-add)*getC(c-have, add)/getC(c, n);
	return res;
}

double simulate() {
	int ntries = 100000;
	double sum = 0;
	REP(z, ntries) {
		vector<char> was(c, 0);
		int cnt = 0;
		while (cnt < c) {
			++sum;
			vector<int> perm(c);
			REP(i, c)
				perm[i] = i;
			random_shuffle(perm.begin(), perm.end());
			REP(i, n) {
				if (!was[perm[i]]) {
					was[perm[i]] = true;
					++cnt;
				}
			}
		}
	}
	return sum/ntries;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int ntests;
	scanf("%d", &ntests);
	FOR(test, 1, ntests) {
		printf("Case #%d: ", test);
		scanf("%d%d", &c, &n);
		vector<double> ans(c+1);
		vector<double> sum(c+1);
		ans[n] = 1;
		sum[n] = 1;
		FOR(k, n, c-1) {
			ans[k] /= sum[k];
			double p0 = prob(k, 0);
			ans[k] += p0/(1-p0);
			FOR(add, 1, c-k) {
				ans[k+add] += sum[k]*prob(k, add)/(1-p0)*(ans[k]+1);
				sum[k+add] += sum[k]*prob(k, add)/(1-p0);
			}
		}
		printf("%.13lf\n", ans[c]/sum[c]);
		//printf("%.13lf\n", simulate());
	}

	exit(0);
}
