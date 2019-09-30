#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F0(i,n) for (int i = 0; i < n; i++)
#define F1(i,n) for (int i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
const int inf = 1000000009;
int i, j, k, m, n, l;
ll R;
int ans;
vector< pair<double, double> > v;
double r;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	//freopen("x.in", "r", stdin);
	
	freopen("C-small-attempt1.in", "r", stdin); //freopen("C-small-attempt0.out", "w", stdout);

	//freopen("C-large.in", "r", stdin); freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		cin >> n >> R;
		cerr << tt << " " << n << " " << R << endl;
		
		if (tt > 50) continue;
		
		r = R * 1e-6;
		ans = 0;
		v.clear();
		for (int d = 1; d <= 2 * n - 2; d++) {
			vector< pair<double, double> > w;
			for (int x = 0; x < n; x++) {
				int y = d - x;
				if (y < 0 || y >= n || x > y) continue;
				if (gcd(x, y) != 1) continue;
				double alp = asin(r / hypot(1.0 * x, 1.0 * y));
				double a0 = atan2(1.0 * y, 1.0 * x);
				double a1 = a0 - alp, a2 = a0 + alp;
				//cout << x << " " << y << " " << a1 << " " << a2 << endl;
				bool covered = false;
				
				int z = lower_bound(v.begin(), v.end(), make_pair(a1, a2)) - v.begin();
				
				for (int u = z - 2; u <= z + 2; u++) if (u >= 0 && u < SZ(v)) {
					auto z = v[u];
					if (z.first <= a1 + eps && z.second >= a2 - eps) {
						covered = true;
						break;
					}
				}
				if (!covered) {
					ans++;
					w.push_back(make_pair(a1, a2));
				}
			}
			for (auto z : v) w.push_back(z);
			sort(w.begin(), w.end());
			v.clear();
			pair<double, double> p = w[0];
			for (int i = 1; i < SZ(w); i++) {
				if (w[i].first > p.second) {
					v.push_back(p);
					p = w[i];
				} else p.second = max(p.second, w[i].second);
			}
			v.push_back(p);
		}
		
  		printf("Case #%d: ", tt);
		cout << 2 * ans - 1 << endl;
	}
	return 0;
}
