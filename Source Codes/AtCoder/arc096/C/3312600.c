#include <stdio.h>
#define ll long long
#define Maxn 3005
int n,mo;
ll C[Maxn][Maxn],g[Maxn][Maxn];
ll mi(ll x,ll y,ll mo)
{
	ll ans=1;
	while (y)
	{
		if (y&1) ans=ans*x%mo;
		x=x*x%mo;
		y>>=1;
	}
	return ans;
}
void pre()
{
	C[0][0]=g[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=g[i][0]=1;
		for (int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1)%mo)%mo;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&mo);pre();
	ll ans=0,now=1;
	for (int i=0;i<=n;i++)
	{
		ll x=0,y=1,X=mi(2,n-i,mo);
		for (int j=0;j<=i;j++)
		{
			x=(x+g[i][j]*y%mo)%mo;
			y=y*X%mo;
		}
		ans=(ans+x*C[n][i]*now%mo*mi(2,mi(2,n-i,mo-1),mo)%mo)%mo;
		now=-now;
	}
	printf("%lld\n",(ans+mo)%mo);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&mo);pre();
  ^