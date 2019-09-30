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

LL n;

int p[1000005];
int cp;
bool np[1000005];

void era() {
	for (int i = 2; i <= 1000000; ++i) {
		if (!np[i]) {
			p[cp++] = i;
			for (LL j = i * LL(i); j <= 1000000; j += i)
				np[j] = true;
		}
	}
}

void alg() {
	scanf("%lld", &n);
	int result = 0;
	for (int i = 0; i < cp && LL(p[i]) * p[i] <= n; ++i) {
		LL c = 1;
		int pw = 0;
		while (c * p[i] <= n) {
			c *= p[i];
			++pw;
		}
		result += pw - 1;
	}
	if (n > 1)
		++result;
	printf("%d\n", result);
}

int main() {
	era();
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: ", testCase);
		alg();
	}
}
