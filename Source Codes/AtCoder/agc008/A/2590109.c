#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll ans=INF;
int main(){
	//A,AB,BA,BAB
	ll x,y;
	scanf("%lld%lld",&x,&y);
	if(y>x)ans=min(ans,y-x);//A
	if(x+y<=0)ans=min(ans,-(x+y)+1);//AB
	if(x+y>=0)ans=min(ans,x+y+1);//BA
	if(y<x)ans=min(ans,x-y+2);//BAB
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&x,&y);
  ^