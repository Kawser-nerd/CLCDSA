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
int was[50];
int use[50];
int g[50][50];
int q[50];
string s[50];
vector<pair<string, int> > w;
                           
int go (int x) {
	if (was[x] == 2 || use[x]) re 0;
	use[x] = 1;
	for (int i = 0; i < n; i++)
		if (g[x][i])
			go (i);
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> s[i];
		memset (g, 0, sizeof (g));
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			g[a][b] = g[b][a] = 1;
		}
		memset (was, 0, sizeof (was));
		int x = 0;
		for (int i = 0; i < n; i++)
			if (s[i] < s[x])
				x = i;
		string res = "";
		int r = 1;
		q[0] = x;
		was[x] = 1;
		while (true) {
			res += s[x];
			for (int i = 0; i < n; i++)
				if (!was[i] && g[x][i]) {
					was[i] = 1;
					w.pb (mp (s[i], i));
				}
			sort (all (w));
			if (sz (w) == 0) break;
			for (int I = 0; I < sz (w); I++) {
				int i = w[I].se;
				for (int j = r - 1; j >= 0; j--)
					if (g[q[j]][i])
						break;
					else
						was[q[j]] = 2;
				memset (use, 0, sizeof (use));
				go (q[0]);
				int ok = 1;
				for (int j = 0; j < n; j++)
					if (was[j] != 2 && !use[j])
						ok = 0;
				if (ok) {
					w.erase (w.begin () + I);
					while (!g[q[r - 1]][i]) r--;
					q[r++] = x = i;
					break;
				}
				for (int j = r - 1; j >= 0; j--)
					if (g[q[j]][i])
						break;
					else
						was[q[j]] = 1;
			}
		}
		cout << "Case #" << it << ": " << res;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}