#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll a[55],b[55],c[55],d[55];
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	rep(i,0,n)scanf("%lld%lld",a+i,b+i);
	rep(i,0,m)scanf("%lld%lld",c+i,d+i);
	rep(i,0,n){
		ll idx=-1,mi=1e10;
		rep(j,0,m){
			ll dist=llabs(a[i]-c[j])+llabs(b[i]-d[j]);
			if(dist<mi){
				mi=dist;
				idx=j;
			}
		}
		printf("%lld\n",idx+1);
	}
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:13:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld%lld",a+i,b+i);
            ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,m)scanf("%lld%lld",c+i,d+i);
            ^