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

const int di[6] = {1, -1, 0, 0, 1, -1};
const int dj[6] = {0, 0, 1, -1, 1, -1};

const string res[8] = {"", "fork", "bridge", "bridge-fork", "ring", "fork-ring", "bridge-ring", "bridge-fork-ring"};

int n;
int m;
int use[6001][6001];
int was[6001][6001];
int q[6001][6001];
int p[36012001];
int x[10000];
int y[10000];
int w[10000];
int f[10000];
int cnt[10000];
ii Q[36012001];
int cur[6];
int ct;
vector<pair<pair<ii, ii>, int> > v, u;

int go (int i, int j, int k) {
	int l = 0, r = 1;
	Q[0] = mp (i, j);
	use[i][j] = ct;
	while (l < r) {
		int i = Q[l].fi;
		int j = Q[l].se;
		l++;
		q[i][j] = k;
		for (int t = 0; t < 6; t++) {
			int ni = i + di[t];
			int nj = j + dj[t];
			if (ni >= 0 && nj >= 0 && ni <= 2 * n && nj <= 2 * n && use[ni][nj] != ct && was[ni][nj] != ct) {
				use[ni][nj] = ct;
				Q[r++] = mp (ni, nj);
			}	
		}
	}	
	re 0;
}

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int good (int x, int y) {
	if (x < 1 || y < 1 || x >= 2 * n || y >= 2 * n) re 0;
	if (x >= f[y] && x <= f[y] + w[y] - 1 && y >= f[x] && y <= f[x] + w[x] - 1) re 1;
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= 2 * n - 1; i++) {
			w[i] = 2 * n - abs (n - i) - 1;
			f[i] = max (1, i - n + 1);
		}	
		ct++;
		v.clear ();
		u.clear ();
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf ("%d%d", &x, &y);
			::x[i] = x;
			::y[i] = y;
			was[x][y] = ct;
			for (int t = 0; t < 6; t++) {
				int nx = x + di[t], ny = y + dj[t];
				if (was[nx][ny] != ct) v.pb (mp (mp (mp (x, y), mp (nx, ny)), i));
				if (was[nx][ny] == ct && good (nx, ny)) u.pb (mp (mp (mp (x, y), mp (nx, ny)), i));
			}
		}
		int r = 0;
		for (int i = 0; i <= 2 * n; i++)
			for (int j = 0; j <= 2 * n; j++)
				if (was[i][j] == ct)
					q[i][j] = r++;
				else 
				if (use[i][j] != ct) {
					go (i, j, r);
					r++;
				}
	        for (int i = 0; i < r; i++) p[i] = i;
		int fring = m + 1;
		for (int i = 0; i < m; i++) cnt[i] = 0;
		for (int i = sz (v) - 1; i >= 0; i--) {
			int x1 = v[i].fi.fi.fi;
			int y1 = v[i].fi.fi.se;
			int x2 = v[i].fi.se.fi;
			int y2 = v[i].fi.se.se;
			int j = v[i].se;
			int a = gp (q[x1][y1]);
			int b = gp (q[x2][y2]);
			if (a != b) {
				if (rand () & 1) p[a] = b; else p[b] = a;
				r--;
				cnt[j]++;
				if (cnt[j] > 1) fring = j;
			}
		}
		r = 0;
		for (int i = 1; i <= 2 * n - 1; i++)
			for (int j = f[i]; j < f[i] + w[i]; j++)
				q[i][j] = r++;
		for (int i = 0; i < r; i++)
			p[i] = i;
		int k = 0;
		int good = 0;
		cout << "Case #" << it << ": ";
		for (int i = 0; i < m; i++) {
			int x = ::x[i];
			int y = ::y[i];
			while (k < sz (u) && u[k].se <= i) {
				int x1 = u[k].fi.fi.fi;
				int y1 = u[k].fi.fi.se;
				int x2 = u[k].fi.se.fi;
				int y2 = u[k].fi.se.se;
				int a = gp (q[x1][y1]);
				int b = gp (q[x2][y2]);
				if (a != b) {
					if (rand () & 1) p[a] = b; else p[b] = a;
				}
				k++;
			}
			int ok = 0, fork = 0, bridge = 0, ring = int (fring == i);
			ok += int (gp (q[1][1]) == gp (q[x][y]));
			ok += int (gp (q[1][n]) == gp (q[x][y]));
			ok += int (gp (q[n][1]) == gp (q[x][y]));
			ok += int (gp (q[n][2 * n - 1]) == gp (q[x][y]));
			ok += int (gp (q[2 * n - 1][n]) == gp (q[x][y]));
			ok += int (gp (q[2 * n - 1][2 * n - 1]) == gp (q[x][y]));
			if (ok >= 2) bridge = 1;
			ok = 0;
			memset (cur, 0, sizeof (cur));
			for (int j = 1; j + 1 < n; j++) {
				cur[0] |= int (gp (q[1][j + 1]) == gp (q[x][y]));
				cur[1] |= int (gp (q[j + 1][1]) == gp (q[x][y]));
				cur[2] |= int (gp (q[j + 1][j + n]) == gp (q[x][y]));
				cur[3] |= int (gp (q[j + n][j + 1]) == gp (q[x][y]));
				cur[4] |= int (gp (q[2 * n - 1][j + n]) == gp (q[x][y]));
				cur[5] |= int (gp (q[j + n][2 * n - 1]) == gp (q[x][y]));
			}
			for (int j = 0; j < 6; j++) ok += cur[j];
			if (ok >= 3) fork = 1;
			if (fork || bridge || ring) {
				printf ("%s in move %d", res[fork + 2 * bridge + 4 * ring].c_str (), i + 1);
				good = 1;
				break;
			}
		}

		if (!good) printf ("none");

		cout << endl;
		cerr << it << endl;
	}
	return 0;
}
