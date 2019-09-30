#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

ll cost[310][310];
ll dddd[310][310];
void waasharuhuroido(ll n){
	rep(i,0,n)rep(j,0,n)dddd[i][j]=cost[i][j];//????????INF?????????
	rep(k,0,n)rep(i,0,n)rep(j,0,n)dddd[i][j]=min(dddd[i][j],dddd[i][k]+dddd[k][j]);
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)rep(j,0,n)scanf("%d",&cost[i][j]);
	waasharuhuroido(n);
	
	ll ans=0;
	rep(i,0,n)rep(j,i+1,n){
		if(cost[i][j]>dddd[i][j]){
			puts("-1");
			return 0;
		}
		int f=0;
		rep(k,0,n)if(k!=i&&k!=j)f|=dddd[i][k]+dddd[k][j]==dddd[i][j];
		if(!f)ans+=dddd[i][j];
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:28: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  rep(i,0,n)rep(j,0,n)scanf("%d",&cost[i][j]);
                            ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:17:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)rep(j,0,n)scanf("%d",&cost[i][j]);
                      ^