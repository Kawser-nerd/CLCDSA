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

int i, j, k, m, n, l, b, t, ans, a[55], v[55];
char ss[1000002];

int main() {
//	freopen("b.in", "r", stdin);
//	freopen("b.out", "w", stdout);

//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt0.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		cin >> n >> k >> b >> t;
		F0(i,n) cin >> a[i];
		F0(i,n) cin >> v[i];
		ans = j = 0;
		for (i = n-1; i >= 0 && k > 0; i--)
			if ( (b-a[i]) > v[i] * t ) j++;
			else { ans += j; k--; }

		printf("Case #%d: ", tt);
		if (k > 0) printf("IMPOSSIBLE");
		else cout << ans;
		cout << endl;
	}
	
	return 0;
}
