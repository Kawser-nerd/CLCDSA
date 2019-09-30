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

int dp[7005][7005];

char s[7005];

int n;

int last[128];

int main() {
	int d;
	scanf("%d", &d);
	int caseNo = 0;
	while (d--) {
		scanf("%s", s);
		n = strlen(s);
		for (int l = n - 1; l >= 0; --l) {
			last['A'] = last['B'] = last['C'] = -1;
			for (int r = l; r < n; ++r) {
				if (l == r)
					dp[l][r] = 2;
				else
					dp[l][r] = dp[l][r - 1] + 2;
				for (int p = l; p < r; ++p)
					if (s[p] == s[r])
						dp[l][r] = min(dp[l][r], dp[l][p] + dp[p + 1][r - 1]);
				if (last[s[r]] != -1)
					dp[l][r] = min(dp[l][r], dp[l][last[s[r]]] + dp[last[s[r]] + 1][r - 1]);
				last[s[r]] = r;
			}
		}
		printf("Case #%d: %d\n", ++caseNo, dp[0][n - 1] + n);
	}
}
