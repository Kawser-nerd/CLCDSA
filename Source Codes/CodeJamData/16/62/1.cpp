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

#define N 11111111
#define mod 1000000007

ll fac[N];
ll ifc[N];
ll der[N];
int main() {
	fac[0] = fac[1] = ifc[0] = ifc[1] = der[0] = 1;
	der[1] = 0;
	for (int i = 2; i < N; i++) {
		ifc[i] = (mod - mod/i) * ifc[mod%i] % mod;
	}
	for (int i = 2; i < N; i++) {
		fac[i] = i * fac[i-1] % mod;
		ifc[i] = ifc[i] * ifc[i-1] % mod;
		der[i] = (i-1) * (der[i-1] + der[i-2]) % mod;
	}
    int z;
    sf("%d", &z);
    fq(cas,z) {
    	int n, k;
    	sf("%d%d", &n, &k);
    	int a = k - 1;
    	int b = n - k;
    	ll ans = 1 - der[a] * der[b] % mod * ifc[a] % mod * ifc[b] % mod;
    	ans %= mod;
    	if (ans < 0) ans += mod;
        pf("Case #%d:", cas);
        pf(" %lld", ans);
        pln;
    }
}
