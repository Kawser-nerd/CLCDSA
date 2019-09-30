#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll cost[110][110];
ll dddd[110][110];

void waasharuhuroido(ll n){
	rep(i,0,n)rep(j,0,n)dddd[i][j]=i==j?0:cost[i][j]?cost[i][j]:INF;
	rep(k,0,n)rep(i,0,n)rep(j,0,n)dddd[i][j]=min(dddd[i][j],dddd[i][k]+dddd[k][j]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		cost[a][b]=cost[b][a]=c;
	}
	waasharuhuroido(n);
	int ans=0;
	rep(i,0,n)rep(j,i+1,n)if(cost[i][j]){
		int f=1;
		rep(ii,0,n)rep(jj,0,n)if(dddd[ii][i]+cost[i][j]+dddd[j][jj]==dddd[ii][jj])f=0;
		ans+=f;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^