#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int a[110];
int main(){
	ll x,y,z,w;
	scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
	rep(i,x,y)a[i]++;
	rep(i,z,w)a[i]++;
	ll ans=0;
	rep(i,0,105)if(a[i]==2)ans++;
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
  ^