#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

#define LIMIT 10000
int divisor[LIMIT+10],md;
void maked(ll n){md=max(md,n);n=min(LIMIT,n);divisor[0]=-1;divisor[1]=1;ll i=2;for(;i*i<=n;i++)if(!divisor[i]){divisor[i]=i;for(ll j=i*i;j<=n;j+=i)if(!divisor[j])divisor[j]=i;}for(;i<=n;i++)if(!divisor[i])divisor[i]=i;}

ll n;
ll d[1010];
int main(){
	maked(2000);
	scanf("%lld",&n);
	rep(i,2,n+1){
		ll t=i;
		while(t!=1){
			d[divisor[t]]++;
			t/=divisor[t];
		}
	}
	ll ans=1;
	rep(i,2,n+1)ans=ans*(d[i]+1)%1000000007;
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^