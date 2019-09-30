#include<cstdio>
const int mod=1000000007;
int n,m,f[3001][3001][2];
int main()
{
	scanf("%d%d",&n,&m);
	f[0][0][1]=1;
	for(int i=1;i<=n;i++)f[0][i][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<2;k++)
			{
				if(j)(f[i+1][j-1][k||!(j-1)]+=f[i][j][k])%=mod;
				if(j)(f[i+1][j][k||!(j-1)]+=f[i][j][k])%=mod;
				if(n-j)(f[i+1][j][k]+=f[i][j][k])%=mod;
				if(n-j)(f[i+1][j+1][k]+=f[i][j][k])%=mod;
			}
	long long ans=0;
	for(int i=0;i<=n;i++)ans+=f[m][i][1];
	printf("%lld\n",ans%mod);
	return 0;
}