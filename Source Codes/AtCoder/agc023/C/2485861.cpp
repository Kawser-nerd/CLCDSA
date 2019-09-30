#include <iostream>
using namespace std;

typedef long long LL;
const LL MOD = 1e9+7;
const int N = 1000000+10;

LL f[N],inv[N];

LL mpow(LL a, LL x) {
    if(x==0) return 1;
    LL t = mpow(a,x/2);
    if(x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}

void init() {
    inv[0]=f[0]=1;
    for(int i=1;i<N;i++) {
        f[i]=f[i-1]*i%MOD;
        inv[i]=mpow(f[i],MOD-2);
    }
}
LL c(LL n, LL m) {
    if(n<m) return 0;
    return f[n]*inv[m]%MOD*inv[n-m]%MOD;
}

LL g[N];
int main() {
    init();
    LL n; cin >> n;
    LL ret = 0; 

    for(LL k=1;k<=n-1;k++) {
        g[k]=f[k]*c(k-1,n-1-k)%MOD;
        //printf("%lld %lld %lld\n", k, g[k], c(k-1,n-1-k));
        ret = ret + k*( (g[k]-g[k-1]*(n-k))%MOD+MOD )%MOD*f[n-1-k]%MOD;
        ret = (ret % MOD + MOD) % MOD;
    }

    cout<<ret<<endl;
}