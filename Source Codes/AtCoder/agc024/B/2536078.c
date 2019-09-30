#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll n;
ll a[200010];

int main(){
	scanf("%lld",&n);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		a[t-1]=i;
	}
	ll ans=1,temp=1;
	rep(i,1,n){
		if(a[i-1]<a[i])temp++;
		else {ans=max(ans,temp);temp=1;}
	}
	ans=max(ans,temp);
	printf("%lld",n-ans);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^