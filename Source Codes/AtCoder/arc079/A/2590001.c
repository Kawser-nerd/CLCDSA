#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n,m;
ll a[200010];
ll b[200010];
int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,m){
		ll p,q;
		scanf("%lld%lld",&p,&q);
		if(p==1)a[q]=1;
		if(q==n)b[p]=1;
	}
	rep(i,2,n)if(a[i]&&b[i]){
		puts("POSSIBLE");
		return 0;
	}
	puts("IMPOSSIBLE");
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&p,&q);
   ^