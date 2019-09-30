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
int a[505], b[505], adj[505], h[505], H[2];
char ss[1000002];

int main() {
//	freopen("e.in", "r", stdin);

	freopen("E-small-attempt0.in", "r", stdin);
	freopen("E-small-attempt0.out", "w", stdout);

//	freopen("E-large.in", "r", stdin);
//	freopen("E-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d: ", tt);
		cin >> n;
		string s;
		map<string, int> M;
		k = 0;
		F0(i,2*n) {
			cin >> s;
			if (M.count(s)) {
				j = M[s];
				a[k] = j;
				b[k] = i;
				k++;
			} else {
				M[s] = i;
			}
		}
		F0(i,n) adj[i] = 0;
		F0(i,n) for(j=i+1;j<n;j++) if (b[i]>a[j] && a[i]<a[j]) { adj[i] |= (1<<j); adj[j] |= (1<<i); }

		ans = inf;

		F0(k,(1<<n)) {
			H[0] = H[1] = 0;
			for (i=0;i<n;i++) {
				if ((1<<i)&k) {
					if (adj[i]&k) break;
					h[i] = 1;
					for(j=0;j<i;j++)
						if ((1<<j)&k)
							if (a[j]>a[i]) h[i] = max(h[i], h[j]+1);
					H[0] = max(H[0], h[i]);
				} else {
					if (adj[i]&((1<<n)-1-k)) break;
					h[i] = 1;
					for(j=0;j<i;j++)
						if ((1<<j)&k); else
							if (a[j]>a[i]) h[i] = max(h[i], h[j]+1);
					H[1] = max(H[1], h[i]);
				}
			}
			if (i==n) {
				ans = min(ans, H[0] + H[1]);
			}
		}

		if (ans == inf) ans = -1;
		cout << ans << endl;
	}
	
	return 0;
}
