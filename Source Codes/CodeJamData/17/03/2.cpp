// '
#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;

ll g(ll n,ll k) {
	--k;
	ll sz=n;
	ll q0=1, q1=0;
	for(;;) {
		if(k<q1) return sz+1;
		k-=q1;
		if(k<q0) return sz;
		k-=q0;

		ll p0=0,p1=0;
		if(sz&1) {
			sz/=2;
			p0 += q0*2;
			p0 += q1;
			p1 += q1;
		} else {
			sz--; sz/=2;
			p0 += q0;
			p1 += q0;
			p1 += q1*2;
		}
		q0=p0, q1=p1;
	}
}


void go(int tn) {
	ll n,k; cin>>n>>k;
	ll Z=g(n,k);

	printf("Case #%d: %lld %lld\n",tn,Z/2,(Z-1)/2);
}




int32_t main() {
	int T; scanf("%d",&T); for(int i=1;i<=T;i++) {
		go(i);
	}
}