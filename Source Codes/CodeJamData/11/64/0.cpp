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

typedef vector<int> VI;

vector<VI> perms;
int n;

bool used[305];

void gen(int x, VI v) {
	if (x == n + 1) {
		perms.PB(v);
		return;
	}
	int mx = 0;
	int need = 1;
	FOREACH (it, v) {
		if (mx > *it)
			need = *it + 1;
		else
			mx = *it;
	}
	for (int i = need; i <= n; ++i) {
		if (!used[i]) {
			used[i] = true;
			v.PB(i);
			gen(x + 1, v);
			v.pop_back();
			used[i] = false;
		}
	}
}

map<VI, int> dp;

vector<VI> posLeft(VI possible, int query) {
	VI res[n + 1];
	FOREACH (it, possible) {
		res[perms[*it][query]].push_back(*it);
	}
	vector<VI> result;
	for (int i = 2; i <= n; ++i)
		if (!res[i].empty())
			result.PB(res[i]);
	return result;
}

int go(VI possible) {
	if (dp.find(possible) != dp.end())
		return dp[possible];
	int ans = n + 1;
	for (int i = 0; i < n; ++i) {
		vector<VI> dv = posLeft(possible, i);
		if (SIZE(dv) == 1 && dv[0] == possible)
			continue;
		int cur = 0;
		FOREACH (it, dv)
			cur = max(cur, go(*it));
		ans = min(ans, cur + 1);
	}
	return dp[possible] = ans;
}

set<pair<int, VI> > vis;

int t[305];

int result;

void ask(int pos, VI possible) {
	if (vis.find(MP(pos, possible)) != vis.end())
		return;
	vis.insert(MP(pos, possible));
	vector<VI> dv = posLeft(possible, t[pos]);
	int mx = 0;
	FOREACH (it, dv)
		mx = max(mx, go(*it));
	if (mx >= go(possible))
		return;
	if (dv.empty()) {
		if (pos == n - 1) {
			result = max(result, possible[0]);
		}
		return;
	}
	FOREACH (it, dv) {
		if (go(*it) == mx)
			ask(pos + 1, *it);
	}
}

void alg(int testCase) {
	result = -1;
	scanf("%d", &n);
	perms.clear();
	dp.clear();
	vis.clear();
	gen(1, vector<int>());
	sort(ALL(perms));
	VI all;
	for (int i = 0; i < SIZE(perms); ++i)
		all.PB(i);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		--t[i];
	}
	ask(0, all);
	printf("Case #%d:", testCase);
	for (int i = 0; i < n; ++i)
		printf(" %d", perms[result][i]);
	printf("\n");
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		alg(testCase);
	}
}
