#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}

#define MOD 1000000007
ll fact[1000010];
ll invfact[1000010];
ll temp[1000010];

ll choose(ll n,ll r){
	if(n<0||r<0||r>n)return 0;
	return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

int main(){
	fact[0]=1;
	rep(i,1,1000005)fact[i]=fact[i-1]*i%MOD;
	invfact[1000000]=pom(fact[1000000],MOD-2,MOD);
	for(ll i=999999;i>=0;i--)invfact[i]=invfact[i+1]*(i+1)%MOD;
	
	ll n;
	scanf("%lld",&n);
	rep(k,0,n)temp[k]=choose(k-1,n-1-k)*fact[k]%MOD*fact[n-1-k]%MOD;
	ll ans=0;
	rep(k,1,n)ans=(ans+k*(temp[k]-temp[k-1]+MOD))%MOD;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^