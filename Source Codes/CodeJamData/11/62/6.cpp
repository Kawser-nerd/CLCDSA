#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

bool good(vector<vi>& a, int x, int y) {
	if (x < 0 || x >= sz(a) || y < 0 || y >= sz(a[x])) return false;
	return true;
}

int get(vector<vi>& a, int x, int y) {
	if (x < 0 || x >= sz(a) || y < 0 || y >= sz(a[x])) return 0;
	return a[x][y];
}

vector<vi> go(vector<vi> a, int M) {
	vector<vi> b = a;
	a = vector<vi>(sz(b), vi(sz(b[0]), 1000 * 1000 * 1000));
	queue<ii> q;
	for (int i = 0; i < sz(a); ++i)
		for (int j = 0; j < sz(a[i]); ++j) 
			for (int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if (!good(a, x, y)) {
					a[i][j] = max(0, b[i][j]);
					q.push(ii(i, j));
				}
			}

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int x = i + dx[dir];
			int y = j + dy[dir];
			if (!good(a, x, y)) continue;			
			if (a[x][y] > max(a[i][j], b[x][y])) {
				a[x][y] = max(a[i][j], b[x][y]);
				q.push(ii(x, y));
			}
		}
	}

	for (int i = 0; i < sz(a); ++i)
		for (int j = 0; j < sz(a[i]); ++j) {
			int opt = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				int hs = a[i][j];
				int ht = get(a, x, y);
				if (hs <= ht) continue;
				opt = max(opt, hs - ht);
			}
			b[i][j] -= min(opt, M);
			b[i][j] = max(b[i][j], 0);
		}
	return b;
}

void solve() {
	int n, m, M;
	cin >> n >> m >> M;
	vector<vi> a(n, vi(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	vector<vi> target(n, vi(m, 0));
	int res = 0;
	while (a != target) {
		a = go(a, M);
		++res;
	}
	cout << res << "\n";
}

int main()
{
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; ++it) {
		printf("Case #%d: ", it + 1);
		solve();
	}
	return 0;
}
