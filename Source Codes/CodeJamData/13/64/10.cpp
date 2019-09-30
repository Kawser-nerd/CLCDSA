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
int w[100000][4];
int g[100000][4];
vii v[100000];
int d;
int K;
set<int> all[100001];

int go (int i, int x) {
	if (i == n) re i;
	int j = -1;
	for (int k = 0; k < d; k++)
		if (g[i][k] == x) {
			j = k;
			break;
		}	
	if (j == -1) re i;
	if (w[i][j] != 0) re w[i][j];
	re w[i][j] = go (i + 1, x);
}

int go (int i, int x, int y) {
	if (i == n) re i;
	int j = go (go (i, x), y);
	if (j == i) re i;
	re go (j, x, y);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d%d", &n, &d, &K);
		for (int i = 0; i < n; i++) {
			v[i].clear ();
			for (int j = 0; j < d; j++) {
				scanf ("%d", &g[i][j]);
				w[i][j] = 0;
			}	
			sort (g[i], g[i] + d);
		}	
		int ai = 0, aj = 0;
		for (int i = 0; i < n; i++) {
			for (int a = 0; a < d; a++)
				if (a == 0 || g[i][a] != g[i][a - 1]) {
					int j = go (i, g[i][a]);
//					printf ("%d %d %d\n", i, A, j);
					for (int b = 0; b < d; b++)
						if (b == 0 || g[j][b] != g[j][b - 1]) {
							int A = g[i][a];
							int B = g[j][b];
							if (A > B) swap (A, B);
							if (all[A].find (B) != all[A].end ()) continue;
							int k = go (j, A, B) - 1;
//							printf ("%d\n", k);
							if (k - i > aj - ai) {
								ai = i;
								aj = k;
							}
							v[k].pb (mp (A, B));
							all[A].insert (B);
						}
				}
			for (int j = 0; j < sz (v[i]); j++)
				all[v[i][j].fi].erase (v[i][j].se);
		}
		cout << "Case #" << it << ": " << ai << " " << aj;

		cout << endl;

		cerr << it << " / " << tt << " " << clock () << endl;
	}
	return 0;
}