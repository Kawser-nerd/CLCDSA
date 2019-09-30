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

const int N = 405;

vector<int> e[N];

vector<int> layer[N];
int dist[N];

int dp[N][N];

int n, m;

bool taken[N];
int countTaken;

void clearTaken() {
	ZERO(taken);
	countTaken = 0;
}

void addTaken(int x) {
	if (taken[x])
		--countTaken;
	taken[x] = true;
	FOREACH (it, e[x]) {
		if (!taken[*it])
			++countTaken;
		taken[*it] = true;
	}
}

void alg() {
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d,%d", &a, &b);
		++a;
		++b;
		e[a].PB(b);
		e[b].PB(a);
	}
	int home = 1, enemy = 2;
	dist[home] = 0;
	layer[0].PB(home);
	for (int i = 0; i <= n; ++i) {
		FOREACH (it, layer[i])
			FOREACH (v, e[*it])
				if (dist[*v] == -1) {
					dist[*v] = dist[*it] + 1;
					layer[i + 1].PB(*v);
				}
	}
	clearTaken();
	addTaken(home);
	FOREACH (v, e[home]) {
		int result = countTaken - taken[*v];
		FOREACH (it, e[*v])
			if (!taken[*it])
				++result;
		dp[home][*v] = result;
	}
	int result = 0;
	if (dist[enemy] == 1)
		result = countTaken;
	for (int i = 0; i + 2 <= n; ++i) {
		FOREACH (u, layer[i]) {
			FOREACH (v, layer[i + 1]) {
				if (dp[*u][*v] != -1) {
					clearTaken();
					addTaken(*u);
					addTaken(*v);
					FOREACH (w, e[*v]) {
						if (dist[*w] != i + 2)
							continue;
						if (*w == enemy)
							result = max(result, dp[*u][*v]);
						int cur = dp[*u][*v] - taken[*w];
						FOREACH (it, e[*w])
							if (!taken[*it])
								++cur;
						dp[*v][*w] = max(dp[*v][*w], cur);
					}
				}
			}
		}
	}
	printf("%d %d\n", dist[enemy] - 1, result);
	for (int i = 0; i <= n; ++i)
		layer[i].clear();
	for (int i = 1; i <= n; ++i)
		e[i].clear();
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: ", testCase);
		alg();
	}
}
