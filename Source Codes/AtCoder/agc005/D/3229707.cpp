#include<cstdio>
#include<algorithm>
#define MOD 924844033
#define MAXN 2006
using namespace std;
int fac[MAXN],vis[MAXN][2],cnt,ed[MAXN*2],d[MAXN*2][MAXN][2],f[MAXN];
long long ans;
int n,k;
int main()
{
	//freopen("captain.in","r",stdin);
	//freopen("captain.out","w",stdout);
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%MOD;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
			if(!vis[i][j])
			{
				int len=0;
				for(int x=i,y=j;x<=n;x+=k,y^=1)
					vis[x][y]=1,len++;
				cnt+=len;
				ed[cnt]=1;
			}
	ed[0]=1;
	d[0][0][0]=1;
	for(int i=0;i<2*n;i++)
		for(int j=0;j<=n;j++)
		{
			d[i+1][j][0]=(d[i][j][0]+d[i][j][1])%MOD;
			if(!ed[i]) d[i+1][j+1][1]=d[i][j][0];
		}
	for(int i=0;i<=n;i++)
		f[i]=(d[n*2][i][0]+d[n*2][i][1])%MOD;
	long long ans=0;
	for(int i=0,j=1;i<=n;j=-j,i++)
		ans=((ans+1ll*f[i]*fac[n-i]*j)%MOD+MOD)%MOD;
	printf("%lld",ans);
}