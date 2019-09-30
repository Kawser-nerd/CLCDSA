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
#include <cassert>

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

const int N = 25;
const int M = 17;

int n;
int m;
int g[N][N];
vi v[2 * N];
int was[2 * N];
int was2[1 << M][2 * N + 1];
int res[1 << M][2 * N + 1];
int sa[1 << M];
int sb[1 << M];
int a, b;
ii w[M];
int ct = 0;
int o;

int go (int x) {
	if (was[x]) re 0;
//	printf ("%d\n", x);
	was[x] = 1;
	if (x < n) a++; else b++;
	for (int i = 0; i < sz (v[x]); i++)
		go (v[x][i]);
	re 0;
}

int go (int i, int j) {
	if (i + 1 == (1 << o)) re j / 2;
	if (was2[i][j] == ct) re res[i][j];
	was2[i][j] = ct;
	int cur = 1e9;
	int k = i;
	while (true) {
		if (k + 1 == (1 << o)) break;
		k = (k + 1) | i;
		int x = k ^ i;
		int a = sa[x];
		int b = sb[x];
		if (j >= abs (a - b)) cur = min (cur, go (k, j - abs (a - b)) + sqr (max (a, b)));
	}
	re res[i][j] = cur;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n;
		for (int i = 0; i < 2 * n; i++) v[i].clear ();
		int now = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				g[i][j] = s[j] - '0';
				if (g[i][j]) {
//					printf ("%d - %d\n", i, j + n);
					now++;
					v[i].pb (j + n);
					v[j + n].pb (i);
				}
			}	
		}
		memset (was, 0, sizeof (was));
		int one = 0;
		o = 0;
		for (int i = 0; i < 2 * n; i++)
			if (!was[i]) {
				a = b = 0;
				go (i);
//				printf ("%d %d\n", a, b);
				if (a + b == 1) one++; else
				if (a == 1 && b == 1) now--; else w[o++] = mp (a, b);
			}
		for (int i = 0; i < (1 << o); i++) {
			int a = 0, b = 0;
			for (int j = 0; j < o; j++)
				if ((i >> j) & 1) {
					a += w[j].fi;
					b += w[j].se;
				}
			sa[i] = a;
			sb[i] = b;
		}
		ct++;
//		assert (go (0, one) <= n * n);
		cout << "Case #" << it << ": " << go (0, one) - now;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
