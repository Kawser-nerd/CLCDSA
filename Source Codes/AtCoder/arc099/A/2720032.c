#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)((n>>m)&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

ll n,k,ans;
ll a[100010];
int main(){
	scanf("%lld%lld",&n,&k);
	k--;n--;
	printf("%lld\n",(n+k-1)/k);
	return 0;
} ./Main.c: In function ‘sortup’:
./Main.c:12:25: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
 void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
                         ^
./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^