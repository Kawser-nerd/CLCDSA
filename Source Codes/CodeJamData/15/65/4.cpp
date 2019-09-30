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
vector<pair<int, ii> > v;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m;
		int ans = 0;
		if (m == 1) {
			for (int i = 0; i < n; i++) {
				int x;
				scanf ("%d", &x);
				if (x > 0) ans += x;
			}
		} else {	
			int ax = 0, ay = 0, bx = 0, by = 0, cx = 0, cy = 0;
			int dx = 0, dy = 0, ex = 0, ey = 0;
			v.clear ();
			for (int i = 0; i < n; i++) {
				int x, y;
				scanf ("%d%d", &x, &y);
				if (x <= 0 && y <= 0) continue;
				if (x >= 0 && y >= 0) {
					cx += x;
					cy += y;
					continue;
				}
				if (x < 0) {
					dx += x;
					dy += y;
					if (x + y > 0) {
						ax += x;
						ay += y;
					}
				} else {
					ex += x;
					ey += y;
					if (x + y > 0) {
						bx += x;
						by += y;
					}
				}
			}
//			printf ("%d %d %d %d | %d %d %d %d | %d %d\n", ax, ay, bx, by, dx, dy, ex, ey, cx, cy);
			ans = max (ans, max (dy, ex));
//			printf ("%d\n", ans);
			ans = max (ans, bx + max (dy + by, 0));
//			printf ("%d\n", ans);
			ans = max (ans, ay + max (ex + ax, 0));
//			printf ("%d\n", ans);
			ans += cx + cy;
		}
		cout << "Case #" << it << ": " << ans << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}