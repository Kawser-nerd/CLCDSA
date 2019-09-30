#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll dp[420][420];
ll ans=INF;

int main(){
	int n,ma,mb;
	scanf("%d%d%d",&n,&ma,&mb);
	rep(i,0,410)rep(j,0,410)dp[i][j]=INF;
	dp[0][0]=0;
	rep(i,0,n){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int aa=400;aa>=0;aa--)for(int bb=400;bb>=0;bb--)if(dp[aa][bb]!=INF)dp[aa+a][bb+b]=min(dp[aa+a][bb+b],dp[aa][bb]+c);
	}
	for(int aa=ma,bb=mb;aa<=400&&bb<=400;aa+=ma,bb+=mb)ans=min(ans,dp[aa][bb]);
	printf("%lld\n",ans==INF?-1:ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&ma,&mb);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^