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
int use[2000], col[2000], p[2000], q[2000];
int cmp[2000][2000];
int was[2000][2000];
int next[2000][2000];
int ea[10000], eb[10000];
int cur[2000];
vi w[2000], v[2000];

int go (int x, int y, int it) {
/*	printf ("%d %d %d:\n", x, y, it);
	for (int i = 0; i < sz (w[x]); i++)	
		printf ("(%d,%d) ", w[x][i] + 1, col[w[x][i]]);
	printf ("\n");*/
	use[x] = it;
	int ok = 1;
	for (int i = 0; i < sz (w[x]); i++)
		if (col[w[x][i]] == 0)
			ok = 0;
	if (!ok) {
		int first = 0, t = sz (w[x]);
		for (int i = 0; i < t; i++)
			if (col[w[x][i]] != 0 && col[w[x][(i + 1) % t]] != 0)
				first = i;
		int second = (first + 1) % t;
//		printf ("%d %d %d %d\n", first, second, col[w[x][first]], col[w[x][second]]);
		int al = 0;
		for (int i = 1; i <= y; i++)
			if (i != col[w[x][first]] && i != col[w[x][second]])
				cur[al++] = i;
		if (col[w[x][first]] != 0) cur[al++] = col[w[x][first]];
		if (col[w[x][second]] != 0) cur[al++] = col[w[x][second]];
		if (col[w[x][first]] == 0) {	
			for (int i = 0; i < t; i++)
				col[w[x][i]] = i + 1;
		} else  {
			int cal = 0;
			for (int i = 0; i < t - 2; i++) {
				int third = (second + 1) % t;
				col[w[x][third]] = cur[cal];
				cal = (cal + 1) % al;
				first = second;
				second = third;
			}
			int third = (second + 1) % t;
			while (col[w[x][second]] == col[w[x][first]] || col[w[x][second]] == col[w[x][third]]) col[w[x][second]] = col[w[x][second]] % y + 1;
		}
//		printf ("ok\n");
	}
	for (int i = 0; i < sz (w[x]); i++) {
		int a = w[x][i];
		int b = w[x][(i + 1) % sz (w[x])];
//		printf ("%d - %d , %d %d %d\n", a, b, was[b][a], cmp[b][a]);
		if (was[b][a] == it && use[cmp[b][a]] != it) go (cmp[b][a], y, it);
	}
	re 0;	
}

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
//		cerr << it << endl;
	        scanf ("%d%d", &n, &m);
	        for (int i = 0; i < m; i++) { scanf ("%d", &p[i]); p[i]--; }
	        for (int i = 0; i < m; i++) { scanf ("%d", &q[i]); q[i]--; }
	        for (int i = 0; i < n; i++) v[i].clear ();
	        int o = 0;
	        for (int i = 0; i < n; i++) {
	        	int j = (i + 1) % n;
	        	v[i].pb (j);
	        	v[j].pb (i);
	        	ea[o] = i;
	        	eb[o] = j;
	        	o++;
	        	eb[o] = i;
	        	ea[o] = j;
	        	o++;
	        }
	        
	        for (int i = 0; i < m; i++) {
	        	v[p[i]].pb (q[i]);
	        	v[q[i]].pb (p[i]);
	        	ea[o] = p[i];
	        	eb[o] = q[i];
	        	o++;
	        	eb[o] = p[i];
	        	ea[o] = q[i];
	        	o++;
		}

		for (int i = 0; i < n; i++) {
			sort (all (v[i]));
			for (int j = 0; j < sz (v[i]); j++)
				next[v[i][j]][i] = v[i][(j + 1) % sz (v[i])];
		}

		int r = 0;
		int res = n + 1, ri = 0;
		for (int i = 0; i < o; i++)
			if (was[ea[i]][eb[i]] != it) {
				w[r].clear ();
				int a = ea[i], b = eb[i];
				do {
//					printf ("%d ", a + 1);
					w[r].pb (a);
					was[a][b] = it;
					cmp[a][b] = r;
					int c = next[a][b];
					a = b;
					b = c;
				} while (a != ea[i] && b != eb[i]);
//				printf ("\n");
				if (sz (w[r]) == n && a < b) use[r] = it; else
				if (sz (w[r]) < res) { res = sz (w[r]); ri = r; }
				r++;
			}
		for (int i = 0; i < n; i++) col[i] = 0;
		go (ri, res, it);
		printf ("Case #%d: %d\n", it, res);
		for (int i = 0; i < n; i++) {
			if (i > 0) printf (" ");
			printf ("%d", col[i]);
		}
		printf ("\n");
/*		for (int i = 0; i < r; i++) {
			int cwas[2001];
			memset (cwas, 0, sizeof (cwas));
			for (int j = 0; j < sz (w[i]); j++) 
				cwas[col[w[i][j]]] = 1;
			int cur = 0;
			for (int j = 1; j <= res; j++)
				cur += cwas[j]; 
			if (cur != res) { 
				printf ("%d %d\n", n, m);
				for (int i = 0; i < m; i++) printf ("%d %d\n", p[i] + 1, q[i] + 1);
				printf ("BAD\n"); 
				re 0; 
			}
		}	*/
	}
	return 0;
}