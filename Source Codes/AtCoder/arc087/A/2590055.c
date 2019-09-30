#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

ll a[200010];
int main(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	sortdown(a,n);
	ll ans=0;
	for(ll i=0;i<n;){
		ll cnt=0,t=i;
		while(a[t]==a[i])cnt++,t++;
		if(cnt>=a[i])ans+=cnt-a[i];
		else ans+=cnt;
		i=t;
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘sortdown’:
./Main.c:11:27: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
 void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
                           ^
./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:17:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^