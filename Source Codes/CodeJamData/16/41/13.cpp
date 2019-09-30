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
typedef pair<short, short> ss;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 12;
const string ch = "RPS";

int n;
int m;

int get (int a, int b) {
	if ((a + 1) % 3 == b) re a;
	re b;
}

vector<pair<ii, int> > q[N + 1];
set<pair<ii, int> > was[N + 1];
map<pair<ii, int>, pair<pair<ss, char>, char> > prev[N + 1];

string out (int n, int a, int b, int d) {
	string res = "";
	if (n == 0) res += ch[d]; else {
		pair<ss, char> p = prev[n][mp (mp (a, b), d)].fi;
		int q = prev[n][mp (mp (a, b), d)].se;
		string s = out (n - 1, p.fi.fi, p.fi.se, p.se);
		string t = out (n - 1, a - p.fi.fi, b - p.fi.se, q);
		res = min (s, t) + max (s, t);
	}
	re res;
}

int main () {
	q[0].pb (mp (mp (1, 0), 0));
	q[0].pb (mp (mp (0, 1), 1));
	q[0].pb (mp (mp (0, 0), 2));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < sz (q[i]); j++) {
//			printf ("%d %d %d = %d\n", q[i][j].fi.fi, q[i][j].fi.se, (1 << i) - q[i][j].fi.fi - q[i][j].fi.se, q[i][j].se);
			for (int k = j; k < sz (q[i]); k++)
				if (q[i][j].se != q[i][k].se) {
					int a = q[i][j].fi.fi + q[i][k].fi.fi;
					int b = q[i][j].fi.se + q[i][k].fi.se;
					int d = get (q[i][j].se, q[i][k].se);
					if (!was[i + 1].count (mp (mp (a, b), d))) {
						q[i + 1].pb (mp (mp (a, b), d));
						was[i + 1].insert (mp (mp (a, b), d));
						prev[i + 1][mp (mp (a, b), d)] = mp (q[i][j], q[i][k].se);
					}
				}
		}
//		printf ("%d = %d\n", i, sz (q[i]));
	}
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		int n, a, b, c;
		scanf ("%d%d%d%d", &n, &a, &b, &c);
		cout << "Case #" << it << ": ";
		string res = "Z";
		if (was[n].count (mp (mp (a, b), 0))) res = min (res, out (n, a, b, 0));
		if (was[n].count (mp (mp (a, b), 1))) res = min (res, out (n, a, b, 1));
		if (was[n].count (mp (mp (a, b), 2))) res = min (res, out (n, a, b, 2));
		if (res == "Z") res = "IMPOSSIBLE";
		cout << res << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}