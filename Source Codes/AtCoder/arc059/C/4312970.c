#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define MOD 1000000007

ll n,c;
ll a[410],b[410];
ll dp[410][410];//dp[i][j]=i?????j?????????
ll cum[410][410];//cum[i][j]=1^i+...+j^i
int main(){
	scanf("%lld%lld",&n,&c);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)scanf("%lld",b+i);
	
	rep(i,0,405)rep(j,1,405)cum[i][j]=(cum[i][j-1]+pom(j,i,MOD))%MOD;

	dp[0][0]=1;
	rep(i,1,n+1)rep(j,0,c+1)rep(k,0,j+1)dp[i][j]=(dp[i][j]+dp[i-1][j-k]*(cum[k][b[i-1]]-cum[k][a[i-1]-1]))%MOD;
	printf("%lld",(dp[n][c]+MOD)%MOD);
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&c);
  ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^
./Main.c:15:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",b+i);
            ^