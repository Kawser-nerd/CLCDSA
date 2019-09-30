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
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
int a[1005], v[1005], d[1005];

int main() {
    //freopen("x.in", "r", stdin);

	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "w", stdout);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		cerr << tt << endl;
		cin >> n; F1(i, n) cin >> a[i];
		int ans = 0;
		F1(i, n) {
			F1(j, n) v[j] = 0; k = 0;
			j = i;
			while (1) {
				v[j] = 1;
				j = a[j];
				k++;
				if (v[j]) break;
			}
			if (j == i)	ans = max(ans, k);
		}
		F1(j, n) v[j] = d[j] = 0;
		F1(j, n) F1(i, n) if (a[a[i]] != i) d[a[i]] = max(d[a[i]], d[i] + 1);
		int ans2 = 0;
		F1(i, n) if (!v[i] && a[a[i]] == i) {
			ans2 += 2 + d[i] + d[a[i]];
			v[i] = v[a[i]] = 1;
		}
		ans = max(ans, ans2);

  		printf("Case #%d: ", tt);
		cout << ans << endl;
	}
	return 0;
}
