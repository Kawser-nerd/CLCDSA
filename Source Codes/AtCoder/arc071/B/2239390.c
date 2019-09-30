#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define M 1000000007

ll x[100010],y[100010];
ll n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,n)scanf("%lld",x+i);
	rep(i,0,m)scanf("%lld",y+i);

	ll xx=0,yy=0;
	rep(i,1,n)xx=(xx+(x[i]-x[i-1])*i%M*(n-i)%M)%M;
	rep(i,1,m)yy=(yy+(y[i]-y[i-1])*i%M*(m-i)%M)%M;
	
	printf("%lld\n",xx*yy%M);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:11:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",x+i);
            ^
./Main.c:12:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,m)scanf("%lld",y+i);
            ^