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

const int INF = 2e9;

int n;
int m;
int x[100], y[100];
int pos[100][101];
vii v;

int dist (int x1, int y1, int x2, int y2) {
	re max (abs (x1 - x2), abs (y1 - y2));
}

int main () {
	double start = clock ();
	double last = clock ();
	int tt;
	cin >> tt;

	for (int it = 1; it <= tt; it++) {
		
		scanf ("%d", &n);
		v.clear ();
		for (int i = 0; i < n; i++) {
			int z;
			scanf ("%d%d%d", &x[i], &y[i], &z);
			v.pb (mp (z, i));
		}

		sort (all (v));

		for (int i = 0; i < n; i++)
			for (int j = 1; j <= n; j++) {
				pos[i][j] = INF;
				if (j == 1 && dist (0, 0, x[v[i].se], y[v[i].se]) * 100 <= v[i].fi + 1000)
					pos[i][1] = max (v[i].fi, dist (0, 0, x[v[i].se], y[v[i].se]) * 100);
			}

		int ans = 0;
		for (int j = 1; j <= n; j++)
			for (int i = 0; i < n; i++)
				if (pos[i][j] < INF) {
					ans = max (ans, j);
					for (int k = 0; k < n; k++) {
						int tmp = pos[i][j] + max (750, dist (x[v[k].se], y[v[k].se], x[v[i].se], y[v[i].se]) * 100);
						if (k != i && tmp <= v[k].fi + 1000 && max (tmp, v[k].fi) < pos[k][j + 1])
							pos[k][j + 1] = max (tmp, v[k].fi);
					}
				}	
		
		cout << "Case #" << it << ": " << ans;



		cout << endl;
		double current = clock ();
		fprintf (stderr, "%d / %d = %.10f : %.10f\n", it, tt, (current - last) / CLOCKS_PER_SEC, (current - start) / CLOCKS_PER_SEC);
		last = current;
	}
	return 0;
}