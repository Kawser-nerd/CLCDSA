#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// BEGIN CUT HERE
#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define sz size()

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
// END CUT HERE

const int MaxK = 16;
const int MaxL = 65536;

int K, N, B;
char str[MaxL];
int best[MaxK][1 << MaxK];
int precalc[MaxK][MaxK];

inline int calculateCost(int a, int b)
{
	int res = 0;
	REP(i, B) {
		int a1 = i*K + a, b1 = i*K + b;
		if (str[a1] != str[b1])
			res++;
	}
	return res;
}

void solve(int iTest)
{
	scanf("%d\n", &K);
	scanf("%s", str);
	N = strlen(str);
	B = N/K;

	REP(i, K) REP(j, K)
		precalc[i][j] = calculateCost(i, j);

	int ans = INF;
	REP(first, K) {
		REP(i, 1 << K) REP(j, K)
			best[j][i] = INF;
		best[first][1 << first] = B;
		for (int mask = 1 << first; mask < (1 << K); mask++) {
			REP(j, K) {
				if (best[j][mask] >= INF)
					continue;

				REP(k, K) {
					if ((1 << k) & mask)
						continue;

					int newMask = mask | (1 << k);
					best[k][newMask] = min(best[k][newMask], best[j][mask] + precalc[j][k]);
				}
			}
		}

		int fullMask = (1 << K) - 1;
		REP(last, K) if (last != first) {
			int currentCost = best[last][fullMask];
			REP(i, B-1) {
				int a1 = i*K + last, b1 = (i+1)*K + first;
				if (str[a1] == str[b1])
					currentCost--;
			}

			ans = min(ans, currentCost);
		}
	}

	printf("Case #%d: %d\n", iTest, ans);
}

int main()
{
	freopen("D-large.in", "rt", stdin);
	freopen("D-large.out", "wt", stdout);
	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 1; iTest <= nTest; iTest++)
		solve(iTest);
	return 0;
}
