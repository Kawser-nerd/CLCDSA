#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))

#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll n;
ll ans;
int main(){
	scanf("%lld",&n);
	while(n--){
		ll n,k;
		scanf("%lld%lld",&n,&k);
		while(n>k){
			ll cnt=(n%k)/(n/k+1);
			n-=cnt*(n/k+1);
			if(n%k==0)break;
			n-=n/k+1;
		}
		ans^=n/k;
	}
	puts(ans?"Takahashi":"Aoki");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&n,&k);
   ^