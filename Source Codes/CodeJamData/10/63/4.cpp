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

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		int k;
		LL C;
		scanf("%d %lld", &k, &C);
		if (C == 1) {
			printf("Case #%d: %d\n", testCase, k);
			continue;
		}
		int res = 0;
		LL sum = 0;
		for (LL i = 1; i <= C; ++i) {
			if (sum / i >= k) {
				i = sum / k;
				continue;
			}
			res += (k - sum / i);
			sum += (k - sum / i) * i;
		}
		printf("Case #%d: %d\n", testCase, res);
	}
}
