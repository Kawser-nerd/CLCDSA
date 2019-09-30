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
int cnt[2501];

int main() {
    //freopen("x.in", "r", stdin);

	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		//cerr << tt << endl;
		cin >> n; F1(i, 2500) cnt[i] = 0;
		F0(i, n*(2 * n - 1)) {
			cin >> j;
			cnt[j] ^= 1;
		}
		printf("Case #%d:", tt);
		F1(i, 2500) if (cnt[i]) cout << " " << i;
		cout << endl;
	}
	return 0;
}
