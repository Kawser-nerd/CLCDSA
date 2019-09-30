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
int cnt[10002];

int main() {
//	freopen("b.in", "r", stdin);

//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt0.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d: ", tt);
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		F0(i,n) {
			cin >> k;
			cnt[k]++;
		}
		vector<int> a, b;
		for (i = 0; i <= 10000; i++) {
			if (cnt[i] < cnt[i+1]) {
				k = cnt[i+1] - cnt[i];
				while (k--)
					a.push_back(i);
			} else {
				k = cnt[i] - cnt[i+1];
				while (k--)
					b.push_back(i);
			}
		}
		ans = 100000;
		F0(i,SZ(a))
			ans = min(ans, b[i]-a[i]);
		if (n == 0) ans = 0;
		cout << ans << endl;
	}
	
	return 0;
}
