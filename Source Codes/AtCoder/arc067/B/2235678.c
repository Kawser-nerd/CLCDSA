#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

ll ans,a,b,n;
ll d[100010];
int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	rep(i,0,n)scanf("%lld",d+i);
	rep(i,0,n-1)ans+=min((d[i+1]-d[i])*a,b);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&a,&b);
  ^
./Main.c:12:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",d+i);
            ^