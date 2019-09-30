#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int a[110][110], d[110][110], n, m, w[110][110];

bool isin(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void solve() {
	int k;
	cin >> n >> m >> k;
	forn(i, n)
		forn(j, m)
			scanf("%d", &a[i][j]);

	int ans = 0;
	while (true) {
		bool one = false;
		forn(i, n)
			forn(j, m)
				one |= (a[i][j] > 0);
		if (!one)
			break;
		ans++;
		forn(x, n)
			forn(y, m) {
				forn(i, n)
					forn(j, m)
						d[i][j] = INF;
				d[x][y] = a[x][y];
				set<pair<int, pair<int, int> > > q;
				q.insert(mp(d[x][y], mp(x, y)));

				while (!q.empty()) {
					int i = q.begin()->sc.fs;
					int j = q.begin()->sc.sc;
					q.erase(q.begin());

					if (i == n - 1 || i == 0 || j == 0 || j == m - 1) {
						w[x][y] = d[i][j];
						break;
					}

					forn(dir, 4) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];

						if (!isin(nx, ny)) 
							continue;

						int nd = max(d[i][j], a[nx][ny]);

						if (d[nx][ny] > nd) {
							q.erase(mp(d[nx][ny], mp(nx, ny)));
							d[nx][ny] = nd;
							q.insert(mp(d[nx][ny], mp(nx, ny)));
						}
					}
				}
			}
		/*
		forn(i, n) {
			forn(j, m)
				cout << w[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
		*/
		forn(x, n)
			forn(y, m) {
				vector<int> v;
				forn(dir, 4) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					int to = 0;
					if (isin(nx, ny))
						to = w[nx][ny];

					if (to < w[x][y])
						v.pb(to);
				}

				sort(all(v));

				int ost = w[x][y];
				forn(t, v.size()) {
					if (ost < v[t])
						break;
					a[x][y] -= min(ost - v[t], k);
					if (a[x][y] < 0)
						a[x][y] = 0;
					ost = v[t];
//					w[x][y] = v[t];
				}
			}
	}

	cout << ans << endl;
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		cerr << ii << ' ' << clock() << endl;
		printf("Case #%d: ", ii + 1);

		solve();
	}

	cerr << clock() << endl;
	
	return 0;
}