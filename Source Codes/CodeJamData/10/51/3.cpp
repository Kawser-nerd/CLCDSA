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
long long p, a, b;
int comp[1000002], x[10001], xmax;
char ss[1000002];

void solve1() {
	if (k == 1) {
		ans = -1;
	} else {
		ans = -2;
		n = 1;
		F0(i,m) n *= 10;
		for (p = xmax+1; p < n; p++) if (!comp[p]) {
			for (a = 0; a < p; a++) {
				b = (x[1] - a * x[0]) % p;
				if (b < 0) b += p;
				for (j = 0; j < k-1; j++)
					if ((a * x[j] + b) % p != x[j+1]) break;
				if (j == 0) throw 9;
				if (j == k-1) {
					l = (a * x[k-1] + b) % p;
					if (ans == -2) ans = l;
					else if (ans != -1 && ans != l) ans = -1;
				}
			}
			if (ans == -1) break;
		}
	}
	if (ans == -2) throw 9;
}

// X^n mod MOD
ll modpow(ll x, ll n, ll MOD) {
	if (n == 0) return 1 % MOD;
	ll y = modpow(x, n/2, MOD);
	y = (y * y) % MOD;
	if (n&1) y = (y * x) % MOD;
	return y;
}

// x^(-1) mod p
ll inv(ll x, ll p) {
	return modpow(x, p-2, p);
}

void solve2() {
	if (k == 1) {
		ans = -1;
	} else if (k == 2) {
		if (x[0] == x[1]) ans = x[0];
		else ans = -1;
	} else if (x[0] == x[1]) {
		ans = x[0];
	} else
	{
		ans = -2;
		n = 1;
		F0(i,m) n *= 10;
		for (p = xmax+1; p < n; p++) if (!comp[p]) {
			// getA
			int P = x[2]-x[1], Q = x[1]-x[0];
			if (Q < 0) {
				P = -P;
				Q = -Q;
			}
			P = (P % p + p) % p;

			a = P;
			a = (a * inv(Q, p)) % p;
			b = (x[1] - a * x[0]) % p;
			if (b < 0) b += p;
			for (j = 0; j < k-1; j++)
				if ((a * x[j] + b) % p != x[j+1]) break;
			if (j <= 1) throw 9;
			if (j == k-1) {
				l = (a * x[k-1] + b) % p;
				if (ans == -2) ans = l;
				else if (ans != -1 && ans != l) ans = -1;
			}
			if (ans == -1) break;
		}
	}
	if (ans == -2) throw 9;
}


int main() {
//	freopen("a.in", "r", stdin);

//	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("A-small-attempt0large.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	comp[0] = comp[1] = 1;
	for (i = 2; i * i <= 1000000; i++)
		if (!comp[i]) {
			for (j = 2*i; j <= 1000000; j += i)
				comp[j] = 1;
		}
	int tt, tn; cin >> tn;
	F1(tt,tn) {
		cin >> m >> k;
		F0(i,k) cin >> x[i];
		xmax = *max_element(x, x+k);

		if (m < 3) 
		solve1();
		else
		solve2();

		printf("Case #%d: ", tt);
		if (ans != -1)
			cout << ans << endl;
		else 
			cout << "I don't know." << endl;
	}
	
	return 0;
}
