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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 80;

int n;
int m;

int eon[N][N][N];
int von[N][N][N];
vii v[N];
int vuse[N];
int euse[N];
int ct;
int g[N];

int dfs (int x, int p, int f) {
	vuse[x] = 1;
	for (int i = 0; i < n; i++)
		von[x][f][i] = vuse[i];
	for (int i = 0; i + 1 < n; i++)
		eon[x][f][i] = euse[i];
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i].fi;
		int z = v[x][i].se;
		if (y == p) continue;
		euse[z] = 1;
		dfs (y, x, f);
		euse[z] = 0;
	}
	vuse[x] = 0;
	re 0;
}

short was[N][N][N][N][2][2];
int res[N][N][N][N][2][2];

int go (int a1, int b1, int a2, int b2, int s1, int s2) {
	if (s1 && s2) re 0;
	if (was[a1][b1][a2][b2][s1][s2] == ct) re res[a1][b1][a2][b2][s1][s2];
	was[a1][b1][a2][b2][s1][s2] = ct;
	int cur = -1e9;
	int ok = 0;
	for (int i = 0; i < sz (v[b1]); i++) {
		int y = v[b1][i].fi;
		int z = v[b1][i].se;
		if (eon[a1][b1][z] || eon[a2][b2][z]) continue;
		ok = 1;
		cur = max (cur, -go (a2, b2, a1, y, s2, s1));
	}
	if (!ok) cur = max (cur, -go (a2, b2, a1, b1, s2, 1));
	if (!s1 && ((!s2 && b1 == b2) || !von[a2][b2][b1])) cur += g[b1];
//	printf ("%d %d %d %d %d %d = %d\n", a1, b1, a2, b2, s1, s2, cur);
	re res[a1][b1][a2][b2][s1][s2] = cur;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &g[i]);
			v[i].clear ();
		}	
		for (int i = 0; i + 1 < n; i++) {
			int x;
			scanf ("%d", &x); x--;
			v[x].pb (mp (i, i));
			v[i].pb (mp (x, i));
//			printf ("%d %d\n", x, i);
		}
		memset (eon, 0, sizeof (eon));
		memset (von, 0, sizeof (von));
		for (int i = 0; i < n; i++)
			dfs (i, i, i);
		ct++;
		int ans = -1e9;
		for (int i = 0; i < n; i++) {
			int cur = 1e9;
			for (int j = 0; j < n; j++) {
				int tmp = go (i, i, j, j, 0, 0);
//				printf ("%d %d = %d\n", i, j, tmp);
				cur = min (cur, tmp);
			}	
			ans = max (ans, cur);
		}
		cout << "Case #" << it << ": " << ans;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}