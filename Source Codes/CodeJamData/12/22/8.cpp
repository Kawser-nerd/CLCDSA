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

int n;
int m, h;
int was[100][100];
int x[100][100];
int y[100][100];
int d[100][100];
int mark[100][100];
ii q[10000];

set<pair<int, ii> > all;

int calc (int l1, int h1, int l2, int h2, int t) {
	if (l2 > h2 - 50 || l1 > h2 - 50 || l2 > h1 - 50) re -1;
	re max (0, 50 - (h2 - (h - t)));
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d%d", &h, &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf ("%d", &y[i][j]);
				d[i][j] = 1e9;
				mark[i][j] = 0;
			}	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf ("%d", &x[i][j]);
		memset (was, 0, sizeof (was));		
		int l = 0, r = 1;
		q[0] = mp (0, 0);
		was[0][0] = 1;
		all.clear ();
		while (l < r) {
			int i = q[l].fi;
			int j = q[l].se;
			all.insert (mp (0, mp (i, j)));
			mark[i][j] = 1;
			d[i][j] = 0;
			l++;
			for (int t = 0; t < 4; t++) {
				int ni = i + int (t == 0) - int (t == 1);
				int nj = j + int (t == 2) - int (t == 3);
				if (ni >= 0 && nj >= 0 && ni < n && nj < m && calc (x[i][j], y[i][j], x[ni][nj], y[ni][nj], 0) == 0 && !was[ni][nj]) {
					was[ni][nj] = 1;
					q[r++] = mp (ni, nj);
				}
			}
		}
		while (!all.empty ()) {
			int i = all.begin ()->se.fi;
			int j = all.begin ()->se.se;
			int ct = all.begin ()->fi;
			all.erase (all.begin ());
			for (int t = 0; t < 4; t++) {
				int ni = i + int (t == 0) - int (t == 1);
				int nj = j + int (t == 2) - int (t == 3);
				if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				int dt = calc (x[i][j], y[i][j], x[ni][nj], y[ni][nj], ct);
				if (dt == -1) continue;
				int nt = ct + dt;
				if (h - nt >= x[i][j] + 20) nt += 10; else nt += 100;
				if (d[ni][nj] > nt) {
					if (mark[ni][nj]) all.erase (mp (d[ni][nj], mp (ni, nj)));
					d[ni][nj] = nt;
					mark[ni][nj] = 1;
					all.insert (mp (nt, mp (ni, nj)));
				}
			}
		}
		cout << "Case #" << it << ": ";
		printf ("%.1f", d[n - 1][m - 1] / 10.0);
		cout << endl;
	}
	return 0;
}