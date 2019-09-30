#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n;
ll a[200010];
ll ans=INF;
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	ll goukei=0;
	rep(i,0,n)goukei+=a[i];
	ll s=0;
	rep(i,0,n-1){
		s+=a[i];
		ans=min(ans,llabs(goukei-2*s));
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:21:15: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
   ans=min(ans,llabs(goukei-2*s));
               ^
./Main.c:8:23: note: in definition of macro ‘min’
 #define min(p,q)((p)<(q)?(p):(q))
                       ^
./Main.c:21:15: warning: incompatible implicit declaration of built-in function ‘llabs’
   ans=min(ans,llabs(goukei-2*s));
               ^
./Main.c:8:23: note: in definition of macro ‘min’
 #define min(p,q)((p)<(q)?(p):(q))
                       ^
./Main.c:21:15: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
   ans=min(ans,llabs(goukei-2*s));
               ^
./Main.c:8:23: note: in definition of macro ‘min’
 #define min(p,q)((p)<(q)?(p):(q))
                       ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:15:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unu...