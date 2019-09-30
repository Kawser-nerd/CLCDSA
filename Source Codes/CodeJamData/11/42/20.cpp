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
char w[501][501];
ll x[501][501];
ll gi[501][501];
ll gj[501][501];
ll s[501][501];

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
	        int d;
		scanf ("%d%d%d", &n, &m, &d);
		gets (w[0]);
		for (int i = 0; i < n; i++) gets (w[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				x[i][j] = w[i][j] - '0' + d;
		for (int i = n; i >= 0; i--)
			for (int j = m; j >= 0; j--)
				if (i == n || j == m)
					gi[i][j] = gj[i][j] = s[i][j] = 0;
				else {
					gi[i][j] = gi[i + 1][j] + gi[i][j + 1] - gi[i + 1][j + 1] + x[i][j] * i;
					gj[i][j] = gj[i + 1][j] + gj[i][j + 1] - gj[i + 1][j + 1] + x[i][j] * j;
					s[i][j] = s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1] + x[i][j];
				}
		int ok = 0, ans;
		for (int k = min (n, m); k > 2; k--) {
			for (int i = 0; i + k <= n && !ok; i++)
				for (int j = 0; j + k <= m && !ok; j++) {
					int I = i + k;
					int J = j + k;
					ll si = gi[i][j] - gi[I][j] - gi[i][J] + gi[I][J];
					ll sj = gj[i][j] - gj[I][j] - gj[i][J] + gj[I][J];
					ll sm = s[i][j] - s[I][j] - s[i][J] + s[I][J];
					si -= x[i][j] * i + x[I - 1][j] * (I - 1) + x[i][J - 1] * i + x[I - 1][J - 1] * (I - 1);
					sj -= x[i][j] * j + x[I - 1][j] * j + x[i][J - 1] * (J - 1) + x[I - 1][J - 1] * (J - 1);
					sm -= x[i][j] + x[I - 1][j] + x[i][J - 1] + x[I - 1][J - 1];
					ll mi = i + I - 1;
					ll mj = j + J - 1;
//					printf ("%d %d %d %d %d %d %d\n", si, sj, sm, s[i][j], s[I][j], s[i][J], s[I][J]);
//					printf ("%d %d %d %d = %.5f %.5f %.1f %.1f\n", i, j, I - 1, J - 1,si / (sm + 0.0), sj / (sm + 0.0), mi / 2.0, mj / 2.0);
					if ((ll)mi * sm == 2 * si && (ll)mj * sm == 2 * sj) ok = 1;
				}
			if (ok) { ans = k; break; }
	        }
		printf ("Case #%d: ", it);
	        if (!ok) printf ("IMPOSSIBLE\n"); else printf ("%d\n", ans);
	}
	return 0;
}