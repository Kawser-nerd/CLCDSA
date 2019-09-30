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

int n;

int cnt[10005];

int starting[10005];

void alg() {
	scanf("%d", &n);
	ZERO(cnt);
	ZERO(starting);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		++cnt[a];
	}
	if (n == 0) {
		printf("0\n");
		return;
	}
	int result = n;
	int l = 1;
	int open = 0;
	for (int i = 1; i <= 10001; ++i) {
		while (open > cnt[i]) {
			int rem = min(starting[l], open - cnt[i]);
			starting[l] -= rem;
			open -= rem;
			if (rem > 0) {
				result = min(result, i - l);
			}
			if (open > cnt[i])
				++l;
		}
		starting[i] = cnt[i] - open;
		open = cnt[i];
	}
	printf("%d\n", result);
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: ", testCase);
		alg();
	}
}
