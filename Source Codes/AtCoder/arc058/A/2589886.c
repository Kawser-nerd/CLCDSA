#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n,k,dame;
int main(){
	scanf("%lld%lld",&n,&k);
	rep(i,0,k){
		ll t;
		scanf("%lld",&t);
		dame|=1LL<<t;
	}
	rep(i,n,1000000){
		ll t=i,flag=0;
		while(t){
			flag|=1LL<<(t%10);
			t/=10;
		}
		if((flag&dame)==0){
			printf("%lld\n",i);
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^