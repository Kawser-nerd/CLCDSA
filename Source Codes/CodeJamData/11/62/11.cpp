#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

int n;
int m;

ll h[50][50];
ll hh[50][50];
ll d[50][50];
ll o;

int check() {
	rep(i, n) rep(j, m)
			if (h[i][j])
				re 0;
	re 1;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline int good(int x, int y) {
	re x > 0 && x < n - 1 && y > 0 && y < m - 1;
}

ll big = (ll)1e16;

void fill1() {
	rep(i, n)
		rep(j, m)
		if (good(i, j))
			hh[i][j] = big;
	rep(z, 100) {
		rep(i, n)
			rep(j, m)
				if (good(i, j)) {
					rep(k, 4) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						hh[i][j] = min(hh[i][j], max(hh[nx][ny], h[i][j]));
					}
				}
	}
}

void drop() {
	rep(i, n) rep(j, m)
	if (good(i, j)) {
		ll u = 0;
		rep(k, 4) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (hh[nx][ny] <= hh[i][j])
				u = max(u, hh[i][j] - hh[nx][ny]);
		}
		d[i][j] = min(u, o);
	}
	rep(i, n) rep(j, m) {
		h[i][j] -= d[i][j];
		if (h[i][j] < 0)
			h[i][j] = 0;
	}
}

void print() {
	rep(i, n) {
		rep(j, m)
			cout << h[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d: ", tt + 1);

		fill(h, 0);
		cin >> n >> m >> o;
		rep(i, n)
			rep(j, m)
				cin >> h[i + 1][j + 1];
		n += 2;
		m += 2;
		int ans = 0;
		//cout << endl;
		while (1) {
			//print();
			if (check())
				break;
			fill1();
			drop();
			ans++;
		}
		cout << ans << endl;
	}


	re 0;
}

