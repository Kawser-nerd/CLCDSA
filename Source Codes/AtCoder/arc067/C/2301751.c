#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
#define M 1000000007

ll fact[1010];
ll invfact[1010];
ll dp[1010][1010];
//dp[i][j]=i??????????????j?????????

int main(){
	int n,a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	fact[0]=1;
	rep(i,1,1005)fact[i]=fact[i-1]*i%M;
	invfact[1000]=invp(fact[1000],M);
	for(int i=999;i>=0;i--)invfact[i]=invfact[i+1]*(i+1)%M;
	
	dp[a-1][n]=1;
	rep(g,a,b+1){
		rep(rest,0,n+1){
			dp[g][rest]=(dp[g][rest]+dp[g-1][rest])%M;
			//???rest???g??????cnt???
			//rest???(g*cnt)?????????????cnt!????????????(g!)^cnt
			rep(cnt,c,min(d,rest/g)+1){
				dp[g][rest-g*cnt]=(dp[g][rest-g*cnt]
								   +dp[g-1][rest]
								   *(fact[rest]*invfact[rest-g*cnt]%M)%M
								   *invfact[cnt]%M
								   *pom(invfact[g],cnt,M)
								  )%M;
			}
		}
	}
	printf("%lld\n",dp[b][0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  ^