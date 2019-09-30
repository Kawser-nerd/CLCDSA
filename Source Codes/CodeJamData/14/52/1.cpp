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

int n;
int m;
short was[101][201][2010][2];
int res[101][201][2010][2];
int ct;
int g[100];
int h[100];
int p, q;

int go (int i, int d, int r, int f) {
	if (i == n) re 0;
	if (was[i][d][r][f] == ct) re res[i][d][r][f];
	was[i][d][r][f] = ct;
	int cur = 0;
	if (d == 0) {
		for (int t = 1; t <= r; t++) {
			if (t * p < h[i])
				cur = max (cur, go (i, t * p, r - t, f));
			else
				cur = max (cur, go (i + 1, 0, r - t, f) + g[i]);	
		}
	}
	if (f) {
		if (d + q < h[i])
			cur = max (cur, go (i, d + q, r, 0));
		else
			cur = max (cur, go (i + 1, 0, r, 0));
	} else {
		cur = max (cur, go (i, d, r + 1, 1));
		if (d + p < h[i])
			cur = max (cur, go (i, d + p, r, 1));
		else
			cur = max (cur, go (i + 1, 0, r, 1) + g[i]);	
	}
//	printf ("%d %d %d %d = %d\n", i, h[i] - d, r, f, cur);
	re res[i][d][r][f] = cur;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d%d", &p, &q, &n);
		for (int i = 0; i < n; i++) scanf ("%d%d", &h[i], &g[i]);
		ct++;
		cout << "Case #" << it << ": " << go (0, 0, 0, 0);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}