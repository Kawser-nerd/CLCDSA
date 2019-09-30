#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int g[400][400];
vi v[400], e[400];
int d[400], was[400], rc[400][400], rt[400][400];
int qi[400 * 400], qj[400 * 400], q[400];

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d", &n, &m);	
		for (int i = 0; i < n; i++) {
			v[i].clear ();
			e[i].clear ();
			for (int j = 0; j < n; j++)
				g[i][j] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf ("%d,%d", &a, &b);
			v[a].pb (b);
			v[b].pb (a);
			g[a][b] = g[b][a] = 1;
		}
		memset (was, 0, sizeof (was));
		int l = 0, r = 1;
		q[0] = 0;
		d[0] = 0;
		was[0] = 1;
		while (l < r) {
			int x = q[l++];
			e[d[x]].pb (x);
			for (int i = 0; i < sz (v[x]); i++) {
				int y = v[x][i];
				if (!was[y]) {
					was[y] = 1;
					q[r++] = y;
					d[y] = d[x] + 1;
				}
			}
		}
		g[1][1] = 1;
		v[1].pb (1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				rc[i][j] = rt[i][j] = 0;
		rc[0][0] = 1;
		rt[0][0] = 1;
		l = 0; r = 1;
		qi[0] = 0;
		qj[0] = 0;
		while (l < r) {
			int x = qi[l];
			int y = qj[l++];
			for (int i = 0; i < sz (v[y]); i++) {
				int z = v[y][i];
				if (rc[y][z] == 0 || rc[y][z] == rc[x][y] + 1) {
					int nt = rt[x][y];
					for (int j = 0; j < sz (e[d[y]]); j++) {
						int k = e[d[y]][j];
						if (k != x && k != z && k != y && (x != 1 && g[x][k] || y != 1 && g[y][k] || z != 1 && g[z][k]))
							nt++;
					}
					if (rc[y][z] == 0 || rc[y][z] == rc[x][y] + 1 && rt[y][z] < nt) {
						if (rc[y][z] == 0) {
							qi[r] = y;
							qj[r++] = z;
						}
						rc[y][z] = rc[x][y] + 1;
						rt[y][z] = nt;
					}
				}
			}
		}
		printf ("Case #%d: %d %d\n", it, rc[1][1] - 3, rt[1][1]);
	}
	return 0;
}