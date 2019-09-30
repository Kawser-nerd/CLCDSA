#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int STEPS = 100000;

double dp[21];

int m, v;

double val(int a) {
	if (a <= 0)
		return 0;
	if (a >= v)
		return 1;
	return dp[a];
}

void imp(int a) {
	for (int b = 1; b <= a && b <= m; ++b) {
		double pr = 1;
		for (int tries = 1; (b << (tries - 1)) <= m; ++tries) {
			pr /= 2;
			dp[a] = max(dp[a], pr * val(a - ((1 << tries) - 1) * b) + (1.0 - pr) * val(a + b));
		}
	}
}

void alg(int testCase) {
	int a;
	scanf("%d %d %d", &a, &m, &v);
	ZERO(dp);
	for (int i = 1; i <= STEPS; ++i) {
		for (int j = 1; j <= v; ++j)
			imp(j);
	}
	int maxBet = -1;
	for (int b = min(a, m); b >= 1; --b) {
		double pr = 1;
		for (int tries = 1; (b << (tries - 1)) <= m; ++tries) {
			pr /= 2;
			double pos = pr * val(a - ((1 << tries) - 1) * b) + (1.0 - pr) * val(a + b);
			if (fabs(pos - dp[a]) < 1e-8) {
				maxBet = b;
				break;
			}
		}
		if (maxBet != -1)
			break;
	}
	printf("Case #%d: %.9lf %d\n", testCase, dp[a], maxBet);
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		alg(testCase);
	}
}
