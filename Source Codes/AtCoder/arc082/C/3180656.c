#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define MOD 998244353

ll n;
ll x[210],y[210];
ll temp[210];

int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld%lld",x+i,y+i);
	rep(i,0,n)rep(j,i+1,n){
		ll c=0;
		rep(k,0,n){
			if((x[i]-x[j])*(y[j]-y[k])==(x[j]-x[k])*(y[i]-y[j]))c++;
		}
		temp[c]++;
	}
	ll ans=pom(2,n,MOD)-1-n;
	rep(i,2,n+1)if(temp[i]){
		ll cnt=temp[i]*2/i/(i-1);
		//????i?????????cnt?
		ans=(ans-(pom(2,i,MOD)-i-1)*cnt)%MOD;
	}
	printf("%lld\n",(ans+MOD)%MOD);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:13:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld%lld",x+i,y+i);
            ^