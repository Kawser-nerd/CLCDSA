#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n;
ll a[100010];
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i+1);
	ll s=0;
	rep(i,0,n+1)s+=llabs(a[i]-a[i+1]);
	rep(i,1,n+1){
		printf("%lld\n",s-llabs(a[i-1]-a[i])-llabs(a[i]-a[i+1])+llabs(a[i-1]-a[i+1]));
	}
} ./Main.c: In function ‘main’:
./Main.c:16:17: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
  rep(i,0,n+1)s+=llabs(a[i]-a[i+1]);
                 ^
./Main.c:16:17: warning: incompatible implicit declaration of built-in function ‘llabs’
./Main.c:16:17: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c:18:21: warning: incompatible implicit declaration of built-in function ‘llabs’
   printf("%lld\n",s-llabs(a[i-1]-a[i])-llabs(a[i]-a[i+1])+llabs(a[i-1]-a[i+1]));
                     ^
./Main.c:18:21: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i+1);
            ^