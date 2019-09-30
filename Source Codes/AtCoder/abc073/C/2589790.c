#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll n;
ll a[100010];
ll ans;
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	sortup(a,n);
	for(ll i=0;i<n;){
		ll t=a[i];
		ll j=i;
		while(a[j]==t)j++;
		ans+=(j-i)%2;
		i=j;
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘sortup’:
./Main.c:11:25: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
 void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
                         ^
./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:18:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^