#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll gcd(ll p,ll q){for(ll t;q;)t=p%q,p=q,q=t;return p;}

ll n,k,M,d;
ll a[100010];
int main(){
	scanf("%lld%lld",&n,&k);
	rep(i,0,n){
		scanf("%lld",a+i);
		M=max(M,a[i]);
		if(i==0)d=a[i];
		else d=gcd(d,a[i]);
	}
	puts(k<=M&&(M-k)%d==0?"POSSIBLE":"IMPOSSIBLE");
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",a+i);
   ^