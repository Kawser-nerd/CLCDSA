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

int was[1000], x1[1000], y1[1000], x2[1000], y2[1000], g[1000][1000], rx, ry;
vi v;

int cross (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	x2++; y2++; x4++; y4++;
	int ax = max (x1, x3);
	int bx = min (x2, x4);
	int ay = max (y1, y3);
	int by = min (y2, y4);
	if (ax > bx || ay > by) return 0;
	if (ax < bx || ay < by) return 1;
	if (x2 == x3 && y1 == y4 || x1 == x4 && y2 == y3) return 1;
	return 0;
}

int go (int c) {
	was[c] = 1;  
	v.push_back (c);
	rx = max (rx, x2[c]);
	ry = max (ry, y2[c]);
	for (int i = 0; i < n; i++)
		if (!was[i] && g[c][i])
			go (i);
	return 0;
}
	
int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (cross (x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j]))
					g[i][j] = g[j][i] = 1;
				else
					g[i][j] = g[j][i] = 0;
		int ans = 0;
		memset (was, 0, sizeof (was));
		for (int i = 0; i < n; i++) 
			if (!was[i]) {
				rx = ry = 0;
				v.clear ();
				go (i);
				for (int j = 0; j < v.size (); j++)
					if (ans < rx - x1[v[j]] + ry - y1[v[j]] + 1)
						ans = rx - x1[v[j]] + ry - y1[v[j]] + 1;
			}
		printf ("Case #%d: %d\n", it + 1, ans);
	}

	return 0;
}