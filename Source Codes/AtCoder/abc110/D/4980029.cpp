#include<iostream>
#include<map>
using namespace std;
const int MAX=210000;
const long long MOD=1000000007;

typedef long long ll;

ll fac[MAX],finv[MAX],inv[MAX];

ll mod_pow(ll x, ll n){
    ll ans=1;
    while(n!=0){
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n=n>>1;
    }
    return ans;
}

void com_init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        //inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        //finv[i]=finv[i-1]*inv[i]%MOD;
        finv[i]=finv[i-1]*mod_pow(i,MOD-2)%MOD;
    }
}

ll comb(ll n, ll k){
    if(n<k) return 0;
    if(n<0||k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

map<ll,ll> prime_factor(ll n){
    map<ll,ll> table;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            table[i]++;
            n/=i;
        }
    }
    if(n!=1) table[n]=1;
    return table;
}

int main(){
    ll n;
    ll m;
    com_init();
    cin >> n >> m;
    
    map<ll,ll> res;
    res=prime_factor(m);

    ll ans=1;

    map<ll,ll>::iterator it;
    for(it=res.begin();it!=res.end();it++){
        ll tmp=comb(it->second+n-1,n-1);
        ans*=tmp;
        ans%=MOD;
    }
    cout << ans << endl;
}