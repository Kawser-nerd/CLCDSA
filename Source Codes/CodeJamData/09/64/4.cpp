#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];
int x[505], y[505], r[505], c[505];
int g[505][505];

int a[505][505], v[505], th;

int rec(int i) {
	v[i] = 1;
	if (i == n+1) return 1;
	for (int j = 0; j <= n+1; j++) 
		if (a[i][j]>=th && !v[j] && rec(j)) {
			a[i][j]-=th;
			a[j][i]+=th;
			return 1;
		}
	return 0;
}

int main() {
//	freopen("d.in", "r", stdin);

//	freopen("D-small-attempt1.in", "r", stdin);
//	freopen("D01.out", "w", stdout);

	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		cin >> n;
		F0(i,n) {
			cin >> x[i] >> y[i] >> r[i] >> c[i];
		}
		memset(g, 0, sizeof(g));
		F0(i,n) F0(j,n) if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= r[i]*r[i]) g[i][j] = 1;
		memset(a, 0, sizeof(a));
		int all = 0;
		F0(i,n) {
			if (c[i] > 0) { a[0][i+1] = c[i]; all += c[i]; }
			else a[i+1][n+1] = -c[i];
			F0(j,n) if (g[i][j])
				a[i+1][j+1] = inf;
		}
		ans = 0;

		th = 1000;
		while (th) {
			for(i = 0; i <= n+1; i++) v[i] = 0;
			if (rec(0)) ans += th; else th /= 2;
		}

		printf("Case #%d: ", tt);
	
		ans = all - ans;
		cout << ans << endl;
	}
	
	return 0;
}
