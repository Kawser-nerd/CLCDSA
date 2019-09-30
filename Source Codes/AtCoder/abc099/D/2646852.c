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

ll n,c,ans;
ll xx[4][99];
ll cc[99][99];
int main(){
	scanf("%lld%lld",&n,&c);
	rep(i,1,c+1)rep(j,1,c+1)scanf("%lld",&cc[i][j]);
	rep(i,0,n)rep(j,0,n){
		ll t;
		scanf("%lld\n",&t);
		xx[(i+j)%3][t]++;
	}
		
	ll ans=INF;
	rep(i,1,c+1)rep(j,1,c+1)if(i!=j)rep(k,1,c+1)if(i!=k&&j!=k){
		ll temp=0;
		rep(x,1,c+1){
			temp+=xx[0][x]*cc[x][i];
			temp+=xx[1][x]*cc[x][j];
			temp+=xx[2][x]*cc[x][k];
		}
		ans=min(ans,temp);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘sortup’:
./Main.c:12:25: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
 void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
                         ^
./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&c);
  ^
./Main.c:20:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,c+1)rep(j,1,c+1)scanf("%lld",&cc[i][j]);
                          ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld\n",&t);
   ^