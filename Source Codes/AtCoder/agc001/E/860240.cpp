#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include "math.h"
#include <complex>
#include <iomanip>
#include <map>
#define ifor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
const double eps = 1e-11;
lli MOD=1000000007;
//Ax=b???A?????
//rankA<=min(m,n)???????vec???

lli fact[10050],factinv[10050];
lli powm(lli a,lli p,lli mod){
  lli ans =1;
  while(p>0){
    if(p&1)ans=(ans*a) % mod;
    a=(a*a)%mod;
    p >>=1;
  }
  return ans%mod;
}

lli inv(lli a){
  return  powm(a,MOD-2,MOD);
}
lli gcd(lli A,lli B){
  if(A%B==0)return B;
  else return gcd(B,A%B);
}

lli cmb(lli a,lli b ){
  lli ans =1;
  rep(i,b){
    ans = ans %MOD* (a-i)%MOD*inv(b-i)%MOD;
  }
  return ans ;
}
lli comb(lli a,lli b){
    return fact[a]%MOD*factinv[b]%MOD*factinv[a-b]%MOD;
}


int main(){
        int N;
        int a[200005],b[200005];
        cin >> N;
        factinv[0]=fact[0]=1;

        rep(i,10020) {
            fact[i+1]=fact[i]*(i+1);
            fact[i+1]%=MOD;
            factinv[i+1]=factinv[i]%MOD*inv(i+1)%MOD;
            factinv[i+1]%=MOD;
        }

        rep(i,N)cin >> a[i]>>b[i];
        lli g[4040][4040];
        rep(i,N){
          g[2010-a[i]][2010-b[i]]++;
        }
        rep(i,4030)rep(j,4030){
          g[i+1][j+1]+=g[i][j+1]%MOD+g[i+1][j]%MOD;
          g[i+1][j+1]%=MOD;
        }
        lli ans =0;
        rep(i,N){
          ans+= g[2010+a[i]][2010+b[i]]%MOD;
          ans%=MOD;
        }

        rep(i,N){
          ans += MOD-comb(2*a[i]+2*b[i],2*a[i])%MOD;
          ans %=MOD;
        }
    if(ans&1)ans+=MOD;
        cout << ans/2 << endl;
}