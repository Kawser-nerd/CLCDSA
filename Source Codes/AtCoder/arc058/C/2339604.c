#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define MOD 1000000007
#define add(x,y) x=(x+y)%MOD
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}

ll dp[50][1<<17];
//dp[i][j]=i????????XYZ??????j???????
//??j=?j?x bit??1?????????????????????x?????????
int main(){
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	ll hit=((1<<a|1)<<b|1)<<c;
	ll M=a+b+c;
	
	dp[0][1]=1;
	rep(i,0,n)repp(j,1,1<<M,2)rep(k,1,11)if(((j<<k)&hit)!=hit)add(dp[i+1][(j<<k|1)&((1<<M)-1)],dp[i][j]);
	ll ans=0;
	repp(j,1,1<<M,2)add(ans,dp[n][j]);
	printf("%lld\n",(pom(10,n,MOD)-ans+MOD)%MOD);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&n,&a,&b,&c);
  ^