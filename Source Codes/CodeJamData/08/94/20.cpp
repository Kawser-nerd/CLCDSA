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

#define N 35

int d[N][N];
bool used[N][N];
queue<pair<int, int> > q;
char f[N][N];
int n, m;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool inMap(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().fs, y = q.front().sc;
		q.pop();
		forn(i, 4) {
			int ty = y + dy[i], tx = x + dx[i];
			if (!inMap(tx, ty) || used[tx][ty] || f[tx][ty] == '.') continue;
			d[tx][ty] = d[x][y] + 1;
			used[tx][ty] = true;
			q.push(mp(tx, ty));
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tk;
	scanf("%d\n", &tk);
	
	for(int tc = 1; tc <= tk; ++tc) {
		scanf("%d %d\n", &n, &m);
		forn(i, n) gets(f[i]);

		memset(used, false, sizeof used);
		forn(i, n)
			forn(j, m)
				if (f[i][j] == 'T') {
					d[i][j] = 0;
					used[i][j] = true;
					q.push(mp(i, j));
				}
		BFS();
		int ans = 0;
		forn(i, n)
			forn(j, m)
				if (f[i][j] != '.') ans += d[i][j];

		int trees = -1;
		forn(i, n)
			forn(j, m)
				if (f[i][j] == 'T') ++trees;
		
		f[0][0] = '#';
		vector<pair<int, int> > cur;
		cur.pb(mp(0, 0));
		forn(iter, trees) {
			memset(used, false, sizeof used);
			forn(i, cur.size()) {
				used[cur[i].fs][cur[i].sc] = true;
				d[cur[i].fs][cur[i].sc] = 0;
				q.push(mp(cur[i].fs, cur[i].sc));
			}

			BFS();

			int len = INF;
			int mnx, mny;
			forn(i, n)
				forn(j, m)
					if (f[i][j] == 'T' && d[i][j] < len) {
						len = d[i][j];
						mnx = i, mny = j;
					}
			
			ans += len * (len + 1) / 2;
			int t = (len - 1) / 2;
			ans -= t * (t + 1);
			if (len % 2 == 0)
				ans -= len / 2;
			f[mnx][mny] = '#';
			cur.pb(mp(mnx, mny));
		}
		printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}