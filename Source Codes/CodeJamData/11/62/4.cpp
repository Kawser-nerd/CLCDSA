#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const ll INF = 1e18;

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int n;
int m;
ll M;
ll g[20][20];
int mark[20][20];
ll d[20][20];
set<pair<ll, ii> > all;

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m >> M;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> g[i][j];
		int ans = 0;
		while (true) {
			int ok = 1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (g[i][j])
						ok = 0;
			if (ok) break;
			ans++;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					mark[i][j] = 0;
					d[i][j] = INF;
					if (i == 0 || j == 0 || i + 1 == n || j + 1 == m) {
						d[i][j] = 0;
						mark[i][j] = 1;
						all.insert (mp (0, mp (i, j)));
					}
				}
			while (!all.empty ()) {
				int i = all.begin()->se.fi;
				int j = all.begin()->se.se;
				all.erase (all.begin ());
				ll cd = d[i][j];
				d[i][j] = max (cd, g[i][j]);
				for (int t = 0; t < 4; t++) {
					int ni = i + di[t];
					int nj = j + dj[t];
					ll nd = max (cd, g[i][j]);
					if (ni >= 0 && nj >= 0 && ni < n && nj < m && d[ni][nj] > nd) {
						if (mark[ni][nj]) all.erase (mp (d[ni][nj], mp (ni, nj)));
						d[ni][nj] = nd;
						mark[ni][nj] = 1;
						all.insert (mp (nd, mp (ni, nj)));
					}
				}
			}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					ll tmp = 0;
					for (int t = 0; t < 4; t++) {
						int ni = i + di[t];
						int nj = j + dj[t];
						if (ni >= 0 && nj >= 0 && ni < n && nj < m)
							tmp = max (tmp, d[i][j] - d[ni][nj]);
						else
							tmp = max (tmp, d[i][j]);
					}
					tmp = min (tmp, M);
					g[i][j] = max (g[i][j] - tmp, (ll)0);
				}
		}
		printf ("Case #%d: %d\n", it, ans);
	}
	return 0;
}
