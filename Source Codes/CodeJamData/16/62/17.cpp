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
const int MOD = 1000000007;

int i, j, k, m, n, l;
int ans;
const int N = 10001;
int d[N][N], vs[N][N], ds[N][N];

void add(int& x, int y) {
	if (y >= MOD) y -= MOD;
	x += y;
	if (x >= MOD) x -= MOD;
}

ll modpow(ll x, ll n) {
	if (n == 0) return 1;
	ll y = modpow(x, n / 2); y = (y * y) % MOD;
	if (n & 1) y = (y * x) % MOD;
	return y;
}

ll rev(ll x) {
	return modpow(x, MOD - 2);
}

int main() {
	//freopen("x.in", "r", stdin);
	
	freopen("B-small-attempt3.in", "r", stdin); freopen("B-small-attempt3.out", "w", stdout);

	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	d[1][1] = 1;
	vs[1][1] = 1;
	ds[1][1] = 1;
	for (int n = 2; n < N; n++) {
		ll p = rev(n - 1);
		for (int i = 1; i <= n; i++) {
			add(d[n][i], MOD + vs[n - 2][i] - vs[i - 1][i]);
			add(d[n][i], MOD + ds[n - 2][i - 2] - ds[n - i][0]);
			d[n][i] = (d[n][i] * p) % MOD;
			vs[n][i] = (vs[n - 1][i] + d[n][i]) % MOD;
			ds[n][i] = (ds[n - 1][i - 1] + d[n][i]) % MOD;
		}
	}

	F1(tt,tn) {
		//cerr << tt << endl;
		cin >> n >> k;
  		printf("Case #%d: ", tt);
		cout << (MOD + 1 - d[n][k]) % MOD << endl;
	}
	return 0;
}
