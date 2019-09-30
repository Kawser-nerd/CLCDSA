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

int r, c;
int h[100][100], w[100][100];

int getW(int i, int j) {
	int& res = w[i][j];
	if (res == -1) {
		int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
		int minH = h[i][j];
		REP(dir, 4) {
			int ni = i+di[dir], nj = j+dj[dir];
			if (0 <= ni && ni < r && 0 <= nj && nj < c)
				remin(minH, h[ni][nj]);
		}
		if (minH == h[i][j])
			return res = i*c+j;
		REP(dir, 4) {
			int ni = i+di[dir], nj = j+dj[dir];
			if (0 <= ni && ni < r && 0 <= nj && nj < c)
				if (h[ni][nj] == minH)
					return res = getW(ni, nj);
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d", &t);
	FOR(test, 1, t) {
		scanf("%d%d", &r, &c);
		REP(i, r) REP(j, c) {
			scanf("%d", &h[i][j]);
			w[i][j] = -1;
		}
		map<int,char> mp;
		char ch = 'a';
		printf("Case #%d:\n", test);
		REP(i, r) {
			REP(j, c) {
				int x = getW(i, j);
				if (!mp.count(x))
					mp[x] = ch++;
				printf("%c ", mp[x]);
			}
			printf("\n");
		}
	}

	exit(0);
}
