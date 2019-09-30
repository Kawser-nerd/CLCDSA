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

int i, j, k, m, n, l;
ll ans;
char ss[1000002];

map<int, int> M;
set<int> S;

int main() {
//	freopen("c.in", "r", stdin);

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

//	freopen("C-large.in", "r", stdin);
//	freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		ans = 0;
		cin >> n;
		M.clear();
		S.clear();
		F0(i,n) {
			cin >> j >> k;
			M[j] = k;
			if (k > 1) S.insert(j);
		}
		while (!S.empty()) {
			i = *S.begin();
			S.erase(S.begin());
			j = M[i] / 2;
			ans += j;
			M[i] -= 2 * j;
			M[i-1] += j;
			if (M[i-1] > 1) S.insert(i-1);
			M[i+1] += j;
			if (M[i+1] > 1) S.insert(i+1);
		}
		printf("Case #%d: ", tt);
		cout << ans << endl;
	}
	
	return 0;
}
