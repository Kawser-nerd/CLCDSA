#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define MAXN 131072
using namespace std;
long long d[41][MAXN],ans,x,y,z,n;
bool check(int p)
{
	if((p&(1<<(x+y+z-1)))&&(p&(1<<(y+z-1))&&(p&(1<<(z-1))))) return 1;
	return 0;
}
long long ksm(long long a,long long m)
{
	if(m==0) return 1;
	long long nex=ksm(a,m/2);
	nex=(nex*nex)%MOD;
	if(m%2==0) return nex;
	else return (nex*a)%MOD;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&x,&y,&z);
	d[0][0]=1;
	for(long long i=0;i<n;i++)
		for(long long j=0;j<MAXN;j++)
		{
			if(d[i][j])
			{
				for(long long k=1;k<=10;k++)
				{
					long long jj=((j<<k)+(1<<(k-1)))%MAXN;
					if(check(jj)) ans=(ans+d[i][j]*ksm(10*1ll,n-i-1))%MOD;
					else d[i+1][jj]=(d[i+1][jj]+d[i][j])%MOD;
				}
			}
		}
	printf("%lld",ans);
}