#include <iostream>
typedef long long ll;
using namespace std;
const int MOD =998244353;
const int N = 300003;
ll fact[N], inv[N];

ll bin(ll n, ll m){
    if(m==1) return n;
    ll nn = bin(n,m/2);
    if(m%2==0){
        return (nn*nn)%MOD;
        //n = (n*n)%MOD;
        //return bin(n,m/2)%MOD;
    }
    return ((n* nn)%MOD*nn)%MOD;
}

void fun(){
    fact[0] =1;
    for(int i=1;i<N;i++){
        fact[i] = (i*fact[i-1])%MOD;
        inv[i] = bin(fact[i],MOD-2);
    }
    inv[0] = 1;
}

ll ncr(int n,int r){
    return ((fact[n]*inv[r])%MOD*inv[n-r])%MOD;
}

int main() {
    ll ans =0;
    ll n,a,b,k;
    fun();
    cin>>n>>a>>b>>k;
    for(int i=0;i<=n;i++){
        if( (k-(a*i))%b!=0) continue;
        int j =  (k-(a*i))/b;
        if(j<0 || j>n) continue;
        ans+=(ncr(n,i)*ncr(n,j))%MOD;
        ans%=MOD;
    }
    cout<<ans;
}