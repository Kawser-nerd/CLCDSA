#include <stdio.h>

typedef long long ll;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

ll mod = 1000000007ll;
//---------------------------------------------------------------------------------------------------
ll f[2010101], rf[2010101];
ll inv(ll x) {
    ll res = 1;
    ll k = mod - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % mod;
        y = (y * y) % mod;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    rep(i, 1, 2010101) f[i] = (f[i - 1] * i) % mod;
    rf[2010101 - 1] = inv(f[2010101 - 1]);
    rrep(i, 2010101 - 2, 0) rf[i] = (rf[i + 1] * (i + 1)) % mod;
}
//---------------------------------------------------------------------------------------------------
ll C(int n, int k) {
    if (k < 0 || n < k) return 0;

    ll a = f[n]; // = n!
    ll b = rf[n - k]; // = (n-k)!
    ll c = rf[k]; // = k!

    ll bc = (b * c) % mod;

    return (a * bc) % mod;
}

int main(){

	int W,H;

	scanf("%d %d",&W,&H);
	W--;
	H--;

	init();

	printf("%lld\n",C(W+H,W));

return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&W,&H);
  ^