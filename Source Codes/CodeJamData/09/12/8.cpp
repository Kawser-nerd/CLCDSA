#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>
using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int64;
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return (int)c.size(); }
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }

#define P pair
#define MP make_pair

int n, m;
int s[20][20], w[20][20], t[20][20];
int64 d[20][20][2][2];
bool was[20][20][2][2];
priority_queue<P<int64,P<P<int,int>,P<int,int> > > > pq;

const int64 inf = 1000000000000000LL;

void update(int i, int j, int i2, int j2, int64 nd) {
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	if (nd == 0)
		nd = 0;
	if (nd < d[i][j][i2][j2]) {
		d[i][j][i2][j2] = nd;
		pq.push(MP(-nd, MP(MP(i, j), MP(i2, j2))));
	}
}

int64 waitW(int64 time, int i, int j) {
	int s = ::s[i][j], w = ::w[i][j], t = ::t[i][j];
	time = ((time-t)%(s+w)+(s+w))%(s+w);
	return time >= s ? 0 : s-time;
}

int64 waitS(int64 time, int i, int j) {
	int s = ::s[i][j], w = ::w[i][j], t = ::t[i][j];
	time = ((time-t)%(s+w)+(s+w))%(s+w);
	return time < s ? 0 : s+w-time;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int ntests;
	scanf("%d", &ntests);
	FOR(test, 1, ntests) {
		printf("Case #%d: ", test);
		scanf("%d%d", &n, &m);
		REP(i, n) REP(j, m) {
			scanf("%d%d%d", &s[i][j], &w[i][j], &t[i][j]);
			REP(i2, 2) REP(j2, 2) {
				d[i][j][i2][j2] = inf;
				was[i][j][i2][j2] = false;
			}
		}
		update(n-1, 0, 1, 0, 0);
		while (!pq.empty()) {
			int i = pq.top().second.first.first, j = pq.top().second.first.second;
			int i2= pq.top().second.second.first, j2 = pq.top().second.second.second;
			pq.pop();
			if (was[i][j][i2][j2]) continue;
			was[i][j][i2][j2] = true;
			int64 curd = d[i][j][i2][j2];
			if (i2) {
				update(i+1, j, i2^1, j2, curd+2);
				update(i, j, i2^1, j2, curd+waitS(curd, i, j)+1);
			} else {
				update(i-1, j, i2^1, j2, curd+2);
				update(i, j, i2^1, j2, curd+waitS(curd, i, j)+1);
			}
			if (j2) {
				update(i, j+1, i2, j2^1, curd+2);
				update(i, j, i2, j2^1, curd+waitW(curd, i, j)+1);
			} else {
				update(i, j-1, i2, j2^1, curd+2);
				update(i, j, i2, j2^1, curd+waitW(curd, i, j)+1);
			}
		}
		printf("%lld\n", d[0][m-1][0][1]);
	}

	exit(0);
}
