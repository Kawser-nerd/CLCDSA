#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

ll dp[2000][2000];
ll p[10000];
ll q[10000];

ll calc(ll a,ll b){
    if(b==0)return 1;
    if(b==1)return a;
    if(b%2==0){
        ll k = calc(a,b/2);
        return k*k%mod;
    }else{
        ll k = calc(a,b/2);
        k *=k;
        k %= mod;
        return k*a %mod;
    }
}

int main(){
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i] =p[i-1]*i%mod;
    }
    q[n] = calc(p[n],mod-2);
    for(ll i=n-1;i>=0;i--){
        q[i] = q[i+1]*(i+1)%mod;
    }
    dp[a-1][0] = 1;
    
    for(int i=a;i<=b;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j]%=mod;
            for(int k=c;k<=d;k++){
                if(j-i*k<0)break;
                ll tmp = q[k]*calc(q[i],k)%mod;
                dp[i][j] += dp[i-1][j-i*k]*tmp%mod;
                dp[i][j] %= mod;
            }
        }
    }
    cout << p[n]*dp[b][n]%mod << endl;
    return 0;
}