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

vector<LL> v1[105];
vector<LL> v2[105];

int s[16];
LL t[16];
int m;

void gen(int x, bool left) {
	if (x == m) {
		if (left) {
			int cnt = 0;
			LL res = 0;
			for (int i = 0; i < m; ++i) {
				cnt += s[i];
				res -= 2 * s[i] * t[i];
				if (cnt <= 0)
					return;
			}
			v1[cnt].push_back(res);
		} else {
			int cnt = 0;
			LL res = 0;
			int lowPoint = 0;
			for (int i = 0; i < m; ++i) {
				cnt += s[i];
				res -= 2 * s[i] * t[i];
				if (i == m - 1 && lowPoint <= cnt)
					return;
				lowPoint = min(lowPoint, cnt);
			}
			if (cnt >= 0)
				return;
			v2[-cnt].push_back(res);
		}
		return;
	}
	for (s[x] = -1; s[x] <= 1; ++s[x])
		gen(x + 1, left);
}

LL a[100];
LL f;

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		for (int i = 0; i <= 100; ++i) {
			v1[i].clear();
			v2[i].clear();
		}
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		scanf("%lld", &f);
		sort(a, a + n);
		m = n / 2;
		for (int i = 0; i < m; ++i)
			t[i] = a[i];
		gen(0, true);
		for (int i = m; i < n; ++i)
			t[i - m] = a[i];
		m = n - m;
		gen(0, false);
		LL res = -1;
		for (int i = 0; i <= 100; ++i) {
			if (v1[i].empty() || v2[i].empty())
				continue;
			sort(ALL(v1[i]));
			sort(ALL(v2[i]));
			int r = v2[i].size() - 1;
			for (int l = 0; l < v1[i].size(); ++l) {
				while (r >= 0 && v1[i][l] + v2[i][r] > f)
					--r;
				if (r < 0)
					break;
				res = max(res, v1[i][l] + v2[i][r]);
			}
		}
		if (res >= 0)
			printf("Case #%d: %lld\n", testCase, res);
		else
			printf("Case #%d: NO SOLUTION\n", testCase);
	}
}
