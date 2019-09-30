#include<cstdio>
#include<algorithm>
#define MAXN 406
#define MOD 1000000007
using namespace std;
long long d[MAXN][MAXN];
int n,c,a[MAXN],b[MAXN];
long long ksm(long long a,int m)
{
	if(m==0) return 1;
	long long nex=ksm(a,m/2);
	nex=nex*nex%MOD;
	if(m%2==0) return nex;
	return nex*a%MOD;
}
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	d[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=c;j++)
		{
			long long sum=0;
			for(int k=a[i];k<=b[i];k++)
				sum=(sum+ksm(1ll*k,j))%MOD;
			for(int l=j;l<=c;l++)
				d[i][l]=(d[i][l]+d[i-1][l-j]*sum)%MOD;
		}
	}
	printf("%lld",d[n][c]);
}