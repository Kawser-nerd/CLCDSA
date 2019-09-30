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

int i, j, m, n, l, wh;
int d[100001];
ll L, a[101], g[101], N, ans, curr, k;
char ss[1000002];
/*
void solve1() {
	memset(d, -1, sizeof(d));
	N = 10000;
	d[0] = 0;
	F0(i,n) {
		F0(j,N)
			if (d[j] != -1 && j+a[i] <= N && (d[j+a[i]] > d[j] + 1 || d[j+a[i]] == -1))
				d[j+a[i]] = d[j] + 1;
	}
	ans = -1;
	F0(i,n) {
		curr = (L-N+a[i]-1) / a[i];
		k = L - a[i] * curr;
		if (d[k] == -1) curr = -1; else curr += d[k];
		if (curr != -1) {
			if (ans == -1 || curr <= ans) {
				wh = i;
				ans = curr;
			}
		}
	}
	cout << n << " " << wh << endl;
}
*/
/*void solve2() {
	g[n-1] = a[n-1];	
	for (i = n-2; i >= 0; i--) {
		g[i] = gcd(g[i+1], a[i]);
		if (L % g[i] == 0) break;
	}
	if (i == -1) {
		ans = -1;
		return;
	}

	ans = 0;
	for (i; i+1 < n; i++) {
		while ((L % g[i+1]) != 0) {
			ans++;
			L -= a[i];
			if (L < 0) throw 9;
		}
	}
	ans += L / a[i];
}*/

void solve3() {

	ll g = a[n-1];
	F0(i,n-1) {
		g = gcd(g, a[i]);
	}
	if (L % g != 0) {
		ans = -1;
		return;
	}

	N = a[n-1];
	int add;
	memset(d, -1, sizeof(d));
	d[0] = 0;

	int jj;
	F0(i,n) {
		F0(jj,N) if (d[jj] != -1) {
			j = jj;
			while (1) {
				k = j+a[i];
				if (k >= N) {
					k -= N;
					add = 1;
				} else add = 0;
				if (d[k] == -1 || d[k] > d[j] + 1 - add) {
					d[k] = d[j] + 1 - add;
				} else break;
				j = k;
			}
		}
		F0(jj,N) if (d[jj] != -1) {
			j = jj;
			while (1) {
				k = j+a[i];
				if (k >= N) {
					k -= N;
					add = 1;
				} else add = 0;
				if (d[k] == -1 || d[k] > d[j] + 1 - add) {
					d[k] = d[j] + 1 - add;
				} else break;
				j = k;
			}
		}

	}
	k = L % N;
	if (d[k] == -1) throw 9;
	ans = d[k] + L / N;
}

int main() {
//	freopen("b.in", "r", stdin);

//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt000.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		cin >> L >> n;
		F0(i,n) cin >> a[i];
		sort(a, a+n);

		solve3();

		printf("Case #%d: ", tt);
		if (ans != -1)
			cout << ans << endl;
		else 
			cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}
