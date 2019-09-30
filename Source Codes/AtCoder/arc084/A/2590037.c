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
ll b[100010];
ll bc[100010];
ll c[100010];
ll ans;
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)scanf("%lld",b+i);
	rep(i,0,n)scanf("%lld",c+i);
	sortup(a,n);
	sortup(b,n);
	sortup(c,n);
	ll cc=0;
	rep(bb,0,n){
		while(cc<n&&c[cc]<=b[bb])cc++;
		if(cc==n)break;
		bc[bb]=n-cc;
	}
	//bc[i]???b[i]????????c???
	for(ll i=n-1;i>0;i--)bc[i-1]+=bc[i];
	//bc[i]??b[i]???b???????(b,c)????
	
	ll bb=0;
	rep(aa,0,n){
		while(bb<n&&b[bb]<=a[aa])bb++;
		if(bb==n)break;
		ans+=bc[bb];
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘sortup’:
./Main.c:11:25: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
 void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
                         ^
./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:21:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^
./Main.c:22:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",b+i);
            ^
./Main.c:23:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",c+i);
            ^