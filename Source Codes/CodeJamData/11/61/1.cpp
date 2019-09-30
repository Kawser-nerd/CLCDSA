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

const int MD = 1000003;

int cnt[26];

int runs;

char buf[1000000];

int dp[105];
int nx[105];

void ad(int& x, LL a) {
	x = (x + a) % MD;
}

LL rfact[500005];
LL fact[500005];

LL choose(int n, int k) {
	if (k > n)
		return 0;
	return (((fact[n] * rfact[k]) % MD) * rfact[n - k]) % MD;
}

int alg() {
	scanf("%s", buf);
	ZERO(cnt);
	runs = 1;
	for (int i = 0; buf[i] != 0; ++i) {
		++cnt[buf[i] - 'a'];
		if (i > 0 && buf[i - 1] != buf[i])
			++runs;
	}
	ZERO(dp);
	dp[0] = 1;
	int total = 0;
	for (int cur = 0; cur < 26; ++cur) {
		if (cnt[cur] == 0)
			continue;
		ZERO(nx);
		for (int blocks = 0; blocks <= runs; ++blocks) {
			for (int newBlocks = 0; newBlocks <= blocks + 1 && newBlocks + blocks <= runs; ++newBlocks) {
				for (int addBlocks = 0; addBlocks <= total - blocks && 2 * addBlocks + newBlocks + blocks <= runs; ++addBlocks) {
					if ((newBlocks == 0 && addBlocks == 0) || (newBlocks + addBlocks > cnt[cur]))
						continue;
					LL ways = choose(total - blocks, addBlocks);
					ways = (ways * choose(blocks + 1, newBlocks)) % MD;
					ways = (ways * choose(cnt[cur] - 1, newBlocks + addBlocks - 1)) % MD;
					ad(nx[blocks + newBlocks + 2 * addBlocks], (ways * dp[blocks]) % MD);
				}
			}
		}
		total += cnt[cur];
		memcpy(dp, nx, sizeof(nx));
	}
	return dp[runs];
}

LL pot(LL a, LL b) {
	LL res = 1;
	for (; b > 0; b >>= 1) {
		if (b & 1)
			res = (res * a) % MD;
		a = (a * a) % MD;
	}
	return res;
}

int main() {
	fact[0] = rfact[0] = 1;
	for (int i = 1; i <= 500000; ++i) {
		fact[i] = (fact[i - 1] * i) % MD;
		rfact[i] = pot(fact[i], MD - 2);
	}
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: %d\n", testCase, alg());
	}
}
