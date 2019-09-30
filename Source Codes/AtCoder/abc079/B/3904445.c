#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll a[99];
int main(){
	a[0]=2;
	a[1]=1;
	rep(i,2,99)a[i]=a[i-1]+a[i-2];
	ll n;
	scanf("%lld",&n);
	printf("%lld",a[n]);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^