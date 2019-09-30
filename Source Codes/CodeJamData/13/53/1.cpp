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
int m;
int p;
int d[2][10000];
int light[10000];
int g[2][10000];
int A[10000];
int B[10000];
int C[10000];
vii v[10000];
set<ii> all;
int mark[10000];
int x[10000];

int go (int t, int s, int sd) {
	all.clear ();
	for (int i = 0; i < n; i++) {
		d[t][i] = 1e9;
		mark[i] = 0;
	}
	d[t][s] = sd;
	mark[s] = 1;
	all.insert (mp (sd, s));
	while (!all.empty ()) {
		int x = all.begin ()->se;
		all.erase (all.begin ());
//		printf ("%d %d = %d\n", t, x, d[t][x]);
		if (t == 1 && d[1][x] > d[0][x]) continue;
		for (int i = 0; i < sz (v[x]); i++) {
			int y = v[x][i].fi;
			int z = g[t][v[x][i].se];
			if (d[t][y] > d[t][x] + z) {
				if (mark[y]) all.erase (mp (d[t][y], y));
				d[t][y] = d[t][x] + z;
				mark[y] = 1;
				all.insert (mp (d[t][y], y));
			}
		}
	}
	if (t == 1 && d[1][1] <= d[0][1]) re 1;
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

	        scanf ("%d%d%d", &n, &m, &p);
	        for (int i = 0; i < n; i++) v[i].clear ();
	        for (int i = 0; i < m; i++) {
	        	int a, b, c, d;
	        	scanf ("%d%d%d%d", &a, &b, &c, &d); a--; b--;
	        	v[a].pb (mp (b, i));
	        	A[i] = c;
	        	B[i] = d;
	        	C[i] = b;
	        }

	        for (int i = 0; i < p; i++) {
	        	scanf ("%d", &x[i]);
	        	x[i]--;
	        }

	        int ans = -1;
	        memset (light, 0, sizeof (light));
		int cur = 0;
	        for (int i = 0; i < p; i++) {
	        	cur += A[x[i]];
	        	light[x[i]] = 1;
	        	for (int j = 0; j < m; j++)
	        		if (light[j]) {
	        			g[0][j] = A[j];
	        			g[1][j] = A[j];
	        		} else {
	        			g[0][j] = B[j];
	        			g[1][j] = A[j];
	        		}
//	        	printf ("try %d\n", x[i] + 1);
	        	go (0, 0, 0);
	        	if (!go (1, C[x[i]], cur)) {
	        		ans = x[i] + 1;
	        		break;
	        	}
	        }
				
		cout << "Case #" << it << ": ";
		if (ans == -1) cout << "Looks Good To Me"; else cout << ans;

		cout << endl;

		cerr << it << " / " << tt << " " << clock () << endl;
	}
	return 0;
}