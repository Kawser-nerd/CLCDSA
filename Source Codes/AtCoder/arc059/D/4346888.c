#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

ll n,m;
ll dp[5010][5010];
//dp[i][j]=i??j?????????
char s[5010];
int main(){
	scanf("%lld %s",&n,s);
	m=strlen(s);
	dp[0][0]=1;
	rep(i,0,n)rep(j,0,i+1){
		dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*2)%MOD;
		dp[i+1][max(0,j-1)]=(dp[i+1][max(0,j-1)]+dp[i][j])%MOD;
	}
	printf("%lld",dp[n][m]*invp(pom(2,m,MOD),MOD)%MOD);
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %s",&n,s);
  ^