#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#define FI first
#define SE second
#define PF push_front
#define PB push_back
#define PPF pop_front
#define PPB pop_back
#define MA make_pair
#define ll long long
#define PA pair<int,int>
#define VE vector<int>
#define VP vector<PA>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int INF=1e9+7;
const int mod=1e9+7;
//
struct poi{
  int X;int Y;int Z;
  bool operator<(const poi&R)const{
    return X==R.X ? Y==R.Y ? Z<R.Z : Y<R.Y : X<R.X;
  }
};
/*
ll GCD(ll A,ll B){
  return (B==0)?(A):(GCD(B,A%B));
}
ll LCM(ll A,ll B){
  return A/GCD(A,B)*B;
}
*/
ll kai[202020];
ll gya[202020];
ll nck[202020];
//
ll pow(ll x,ll n,ll mod){
	ll res=1;
  	if(n>0){
		res=pow(x,n/2,mod);
    	if(n%2==0){
    		res=(res*res)%mod;
    	}else{
    		res=(((res*res)%mod)*x)%mod;
    	}
  	}
	return res;
}
//
ll inv(ll n,ll mod){
	return pow(n,mod-2,mod);
}
//
void nCk(ll N,ll mod){
    kai[N]=N;
    ROF(i,1,N){
		(kai[i]=kai[i+1]*i)%=mod;
    }
    gya[1]=inv(1,mod);
    FOR(i,2,N+1){
        (gya[i]=gya[i-1]*inv(i,mod))%=mod;
    }
    FOR(i,1,N){
        (nck[i]=kai[N+1-i]*gya[i])%=mod;
    }
    nck[0]=1;nck[N]=1;
}
//
ll a[202020],b[202020];
int main(){
	ll H,W,A,B;
	cin>>H>>W>>A>>B;
	nCk(H-A+B-1,mod);
	FOR(i,0,H-A){
		a[i]=nck[i];
	}
	nCk(W-B+A-1,mod);
	FOR(i,0,W-B){
		b[i]=nck[i];
	}
	//
	ll ans=0;
	ll aa=H-A-1,bb=W-B-1;
	while(aa>=0&&bb>=0){
		(ans+=(a[aa]*b[bb]%mod))%=mod;
		aa--;bb--;
	}
	cout<<ans<<endl;
	return 0;
}