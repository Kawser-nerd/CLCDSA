#include <cstdio>
#include <iostream>
#define N 300005
#define mod 1000000007
#define ll long long
using namespace std;
ll up,n,m,k;
ll ans=0,fac[N*3],ifac[N*3],mul[N*3];
inline ll calc(int a,int b){return fac[a]*ifac[b]%mod*ifac[a-b]%mod;}
inline ll ksm(ll x,int p){
	ll ret=1;
	while(p){
		if(p&1)ret=ret*x%mod;
		x=x*x%mod,p>>=1;
	}
	return ret;
}
int main(){
	cin>>n>>m>>k,up=n+m+k,fac[0]=mul[0]=ifac[1]=ifac[0]=1;
	for(ll i=2;i<=up;++i)ifac[i]=(mod-mod/i)*ifac[mod%i]%mod;
	for(ll i=1;i<=up;++i)mul[i]=mul[i-1]*3%mod,(ifac[i]*=ifac[i-1])%=mod,fac[i]=fac[i-1]*i%mod;
	if(m<k)m^=k,k^=m,m^=k;
	for(ll i=0,j=1;i<=m+k;++i){
		(ans+=calc(n-1+i,n-1)*mul[m+k-i]%mod*j%mod)%=mod;
		if(i<k)(j<<=1)%=mod;
		else if(i>=m)(j+=j-calc(i,k)-calc(i,i-m))%=mod;
		else (j+=j-calc(i,k))%=mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}