#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int a[110][110];
int main(){
	ll w,h,n;
	scanf("%lld%lld%lld",&w,&h,&n);
	rep(i,0,n){
		ll x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		if(c==1)rep(xx,0,x)rep(yy,0,h)a[xx][yy]++;
		if(c==2)rep(xx,x,w)rep(yy,0,h)a[xx][yy]++;
		if(c==3)rep(xx,0,w)rep(yy,0,y)a[xx][yy]++;
		if(c==4)rep(xx,0,w)rep(yy,y,h)a[xx][yy]++;
	}
	ll ans=0;
	rep(xx,0,w)rep(yy,0,h)ans+=!!a[xx][yy];
	printf("%lld",w*h-ans);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&w,&h,&n);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&x,&y,&c);
   ^