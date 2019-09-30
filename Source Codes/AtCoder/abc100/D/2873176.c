#include <stdio.h>
#include <stdlib.h>
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

ll n,m,ans;
ll x[1010],y[1010],z[1010];
ll q[1010];

int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,n)scanf("%lld%lld%lld",x+i,y+i,z+i);
	rep(j,0,8){
		rep(i,0,n)q[i]=(bit(j,2)?x[i]:-x[i])+(bit(j,1)?y[i]:-y[i])+(bit(j,0)?z[i]:-z[i]);
		sortdown(q,n);
		ll temp=0;
		rep(i,0,m)temp+=q[i];
		ans=max(ans,temp);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:22:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld%lld%lld",x+i,y+i,z+i);
            ^