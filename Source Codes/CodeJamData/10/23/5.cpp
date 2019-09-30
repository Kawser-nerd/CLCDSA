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
const int MOD = 100003;
int i, j, k, m, n, l, ans;
char ss[1000002];
int a[555][555], C[555][555];

int main() {
//	freopen("c.in", "r", stdin);
//	freopen("c.out", "w", stdout);

//	freopen("C-small-attempt0.in", "r", stdin);
//	freopen("C-small-attempt0.out", "w", stdout);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	for (i = 0; i <= 500; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}

	for (i = 2; i <= 500; i++) 
		for (j = 1; j < i; j++) {
			if (j == 1) a[i][j] = 1; else {
				a[i][j] = 0;
				for (k = 1; k < j; k++) if (i-j-1 >= j-k-1) {
					a[i][j] = (a[i][j] + a[j][k] * (long long)C[i-j-1][j-k-1]) % MOD;
				}
			}
		}

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		cin >> n;
		printf("Case #%d: ", tt);
		ans = 0;
		for (i = 1; i <= n; i++)
			ans = (ans + a[n][i]) % MOD;
		cout << ans << endl;
	}
	
	return 0;
}
