#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 5006
#define MOD 1000000007
using namespace std;
long long d[MAXN][MAXN];
int n,m;
char s[MAXN];
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
	scanf("%d",&n);
	scanf("%s",s);
	m=strlen(s);
	d[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
		{
			d[i+1][j+1]+=d[i][j]*2;
			d[i+1][j+1]%=MOD;
			d[i+1][max(j-1,0)]+=d[i][j];
			d[i+1][max(j-1,0)]%=MOD;
		}
	printf("%lld",d[n][m]*ksm(500000004,m)%MOD);
}