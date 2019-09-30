#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

ll MAXMOD = 0;

struct rat {

	ll a;
	ll b;

	rat() {a = 0, b = 1;}
	rat(ll _a, ll _b) {a = _a, b = _b; norm();}
	rat(ll _a) {
		a = _a;
		b = 1;
	}
	void norm() {
		if (a > MAXMOD) MAXMOD = a;
		ll d = __gcd(a, b);
		if (d != 0) {
			a /= d;
			b /= d;
		}
		if (b < 0) {
			a = -a;
			b = -b;
		}
	}
	rat operator + (const rat &x) const {
		return rat(a * x.b + b * x.a, b * x.b);
	}
	rat operator - (const rat &x) const {
		return rat(a * x.b - b * x.a, b * x.b);
	}
	rat operator * (const rat &x) const {
		return rat(a * x.a, b * x.b);
	}
	rat operator / (const rat &x) const {
		return rat(a * x.b, b * x.a);
	}
	bool operator < (const rat &x) const {
		return a * x.b < b * x.a;
	}
	bool operator <= (const rat &x) const {
		return a * x.b <= b * x.a;
	}
	bool operator == (const rat &x) const {
		return a * x.b == b * x.a;
	}
	rat operator -() const {
		return rat(-a, b);
	}
	double dvalue() {
		return 1. * a / b;
	}
};

#define maxn 110
const rat INF((ll)1e17);


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int T;
int n, m;
int f[maxn][maxn], c[maxn][maxn];
int H;

rat minT[maxn][maxn][4]; // min time to be able to go to here
rat d[maxn][maxn];

typedef pair <rat, pii> pdi;

set <pdi> s;

int main() {
  scanf("%d", &T);
  for (int q = 1; q <= T; q++) {
  	scanf("%d %d %d", &H, &n, &m);
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < m; j++) {
  			scanf("%d", &c[i][j]);
  		}
  	}
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < m; j++) {
  			scanf("%d", &f[i][j]);
  		}
  	}

  	// calc edges
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < m; j++) {
  			for (int k = 0; k < 4; k++) {
  				int x = i + dx[k], y = j + dy[k];
  				if (x < 0 || y < 0 || x >= n || y >= m) {
  					minT[i][j][k] = INF;
  					continue;
  				}
  				if (c[x][y] - f[x][y] < 50) {
  					minT[i][j][k] = INF;
  					continue;
  				}
  				if (c[x][y] - f[i][j] < 50) {
  					minT[i][j][k] = INF;
  					continue;
  				}
  				if (c[i][j] - f[x][y] < 50) {
  					minT[i][j][k] = INF;
  					continue;
  				}
  				if (c[x][y] - H >= 50) {
  					minT[i][j][k] = 0;
  				} else {
  					minT[i][j][k] = rat(H - (c[x][y] - 50), 10);
  				}

  				// printf("(%d %d -> %d %d) : %.5lf\n", i, j, x, y, minT[i][j][k].dvalue());
  			}
  		}
  	}

  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < m; j++) {
  			d[i][j] = INF;
  		}
  	}

  	d[0][0] = 0;
  	s.insert(pdi(0, pii(0, 0)));
  	while (sz(s)) {

  		pdi curp = *s.begin();
  		s.erase(s.begin());
  		int i = curp.y.x, j = curp.y.y;
  		if (d[i][j] < -curp.x) {
  			continue;
  		}
  		rat curtime = d[i][j];
  		for (int k = 0; k < 4; k++) {
  			if (minT[i][j][k] == INF) continue;
  			rat togo = minT[i][j][k] < curtime ? curtime : minT[i][j][k];
  			rat wlevel = rat(H) - togo * rat(10);

  			rat walktime = rat(1);
  			if (togo == 0) {
  				walktime = 0;
  			} else if (wlevel - rat(f[i][j]) < rat(20)) {
  				walktime = rat(10);
  			}

  			rat newtime = togo + walktime;
  			int x = i + dx[k], y = j + dy[k];
  			if (newtime < d[x][y]) {
  				d[x][y] = newtime;
  				s.insert(pdi(-newtime, pii(x, y)));
  			}
  		}
  	}


  	rat ans = d[n - 1][m - 1];
  	printf("Case #%d: %.10lf\n", q, ans.dvalue());
  }

  debug("%lld\n", MAXMOD);
  

  return 0;
}
