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

int dp[1005][1005];

PII e[1005];

int n;

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		int n;
		scanf("%d", &n);
		dp[1][2] = dp[1][3] = dp[2][3] = 1;
		int res = 0;
		for (int i = 4; i <= n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a > b)
				swap(a, b);
			e[i] = MP(a, b);
			dp[a][i] = dp[b][i] = 1;
		}
		for (int i = n; i >= 4; --i) {
			res = max(res, dp[e[i].ST][e[i].ND] + dp[e[i].ST][i] + dp[e[i].ND][i]);
			dp[e[i].ST][e[i].ND] = max(dp[e[i].ST][e[i].ND], dp[e[i].ST][i] + dp[e[i].ND][i]);
		}
		res = max(res, dp[1][2] + dp[2][3] + dp[1][3]);
		printf("Case #%d: %d\n", testCase, res);
	}
}
