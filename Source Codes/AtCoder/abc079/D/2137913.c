#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1<<30)-(1<<15))

ll cost[20][20];
ll dddd[20][20];
void waasharuhuroido(ll n){
	rep(i,0,n)rep(j,0,n)dddd[i][j]=cost[i][j];
	rep(k,0,n)rep(i,0,n)rep(j,0,n)dddd[i][j]=min(dddd[i][j],dddd[i][k]+dddd[k][j]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,10)rep(j,0,10)scanf("%lld",&cost[j][i]);
	waasharuhuroido(10);
	ll ans=0;
	rep(i,0,m)rep(j,0,n){
		int t;
		scanf("%d",&t);
		if(t!=-1)ans+=dddd[1][t];
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:17:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,10)rep(j,0,10)scanf("%lld",&cost[j][i]);
                        ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^