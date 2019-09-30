#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:60000000")

#include <iostream>
#include <sstream>

#include <cassert>
#include <cmath>
#include <ctime>

#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()

const int INF = INT_MAX >> 1;
const double EPS = 1E-8;
const double PI = 3.1415926535897932384626433832795;

int dx1, dx2, dy1, dy2, W, H, X, Y;

bool inMap(int x, int y) {
	return 0 <= x && x < W && 0 <= y && y < H;
}

int stupid() {
	set<pair<int, int>> used;
	queue<pair<int, int>> q;
	q.push(mp(X, Y));
	used.insert(mp(X, Y));
	while (!q.empty()) {
		int x = q.front().fs, y = q.front().sc;
		q.pop();
		int tx = x + dx1, ty = y + dy1;
		if (inMap(tx, ty) && !used.count(mp(tx, ty))) {
			q.push(mp(tx, ty));
			used.insert(mp(tx, ty));
		}
		tx = x + dx2, ty = y + dy2;
		if (inMap(tx, ty) && !used.count(mp(tx, ty))) {
			q.push(mp(tx, ty));
			used.insert(mp(tx, ty));
		}
	}
	return (int)used.size();
}

pair<int, int> bounds(int x, int dx, int M) {
	if (dx == 0) {
		if (0 <= x && x < M) return mp(-INF, INF);
		return mp(1, 0);
	}
	int l = -x, r = M - x - 1;
	if (dx < 0) {
		swap(l, r);
		l = -l;
		r = -r;
		dx = -dx;
	}
	if (l < 0) l = 0;
	if (l > r) return mp(l, r);
	if (l % dx == 0) l = l / dx;
	else l = l / dx + 1;
	return mp(l, r / dx);
}

int64 solve() {
	if (dx1 * dy2 == dx2 * dy1) return stupid();

	int64 res = 0;
	pair<int, int> prev = mp(-INF, INF);
	for(int i = 0; i <= 1000000; ++i) {
		int x = X + dx1 * i;
		int y = Y + dy1 * i;
		pair<int, int> b1 = bounds(x, dx2, W), b2 = bounds(y, dy2, H);
		pair<int, int> kk = mp(0, INF);
		kk.fs = max(kk.fs, b1.fs);
		kk.sc = min(kk.sc, b1.sc);

		kk.fs = max(kk.fs, b2.fs);
		kk.sc = min(kk.sc, b2.sc);

		if (kk.fs > kk.sc) break;
		if (max(prev.fs, kk.fs) > min(prev.sc, kk.sc)) break;
		res += kk.sc - kk.fs + 1;
		prev = kk;
	}
	int res2 = stupid();
	if (res2 != res) throw;
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tk;
	scanf("%d\n", &tk);
	
	for(int tc = 1; tc <= tk; ++tc) {
		cin >> W >> H >> dx1 >> dy1 >> dx2 >> dy2 >> X >> Y;
		printf("Case #%d: %I64d\n", tc, solve());
	}

	return 0;
}