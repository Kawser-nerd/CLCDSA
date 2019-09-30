#include <bits/stdc++.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
using namespace std;

map<ll,ll> memo;
ll isqrt(ll n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	ll s = (ll)sqrt(n);
	while (s * s< n) s++;
	while (s*s > n) s--;
	return s;
}
ll count(ll b, ll r) {
	// x^2 + y^2 <= r, (x, y) != (0, 0)
	ll ans = 0;
	for (ll x = 0; x <= b && x*x <= r; x++) {
		ll y = isqrt(r - x*x);
		y = min(y, b);
		ans += y + 1;
	}
	ans--;
	// printf("%lld %lld: %lld\n", b, r, ans);
	return ans;
}
#define N 1111111
bool isp[N];
int mu[N];
int main() {
	for (int i = 0; i < N; i++) isp[i] = true, mu[i] = 1;
	for (int i = 2; i < N ;i++) {
		if (isp[i]) {
			for (int j = i; j < N; j += i) mu[j] = -mu[j];
			if (i <= N / i) for (int j = i*i; j < N; j += i*i) mu[j] = 0;
			for (int j = i << 1; j < N; j += i) isp[j] = false;
		}
	}
    int z;
    sf("%d", &z);
    fq(cas,z) {
    	memo.clear();
    	ll n, r;
    	sf("%lld%lld", &n, &r);
    	r = 999999999999ll / r / r;
    	// printf("n = %lld, r = %lld\n", n, r);
    	ll ans = 0;
    	for (ll d = 1; d * d <= r; d++) {
    		ans += mu[d] * count((n-1) / d, r / d / d);
    	}
        pf("Case #%d: %lld\n", cas, ans);
    }
}
