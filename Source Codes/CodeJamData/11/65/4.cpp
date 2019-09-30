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
ll m, a, v;
double res[401];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
		cin >> a >> m >> v;
		memset (res, 0, sizeof (res));
		for (int IT = 0; IT < 10000; IT++) {
			int ok = 1;
			for (int i = v - 1; i > 0; i--)
				for (int j = 1; j <= min (i, (int)m); j++) {
					double prob = 0, cur, tmp = 1;
					int sum = 0;
					for (int k = 0; (j << k) <= m; k++) {
						sum += (j << k);
						tmp /= 2;
						prob += tmp;
						cur = 0;
						if (i - sum > 0) cur += tmp * res[i - sum];
 						if (i + j < v) cur += prob * res[i + j]; else cur += prob;
						if (cur > res[i]) {
							res[i] = cur;
							ok = 0;
						}
					}
				}
			if (ok) break;
		}
		int ans = min (a, m);
		while (ans > 1) {
			double prob = 0, cur, tmp = 1, fans = 0;
			int sum = 0;
			for (int k = 0; (ans << k) <= m; k++) {
				sum += (ans << k);
				tmp /= 2;
				prob += tmp;
				cur = 0;
				if (a - sum > 0) cur += tmp * res[a - sum];
				if (a + ans < v) cur += prob * res[a + ans]; else cur += prob;
				fans = max (fans, cur);
			}
			if (fabs (fans - res[a]) < 1e-6) break;
			ans--;
		}
		printf ("Case #%d: %.9f %d\n", it, res[a], ans);
	}
	return 0;
}
