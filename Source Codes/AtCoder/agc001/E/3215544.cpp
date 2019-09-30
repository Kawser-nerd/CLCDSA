#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long MAXM=4005,MAXN=8005,MOD=1e9+7;
long long n;
long long jc[MAXN],dp[MAXM][MAXM],ask[MAXM][MAXM];
long long Inv[MAXN];
long long ksm(long long x,long long y)
{
	long long k=1;
	while(y)
	{
		if(y&1)
			k=(k*x)%MOD;
		x=(x*x)%MOD;
		y>>=1;
	}
	return k;
}
void Init()
{
	jc[0]=1;
	for(long long i=1;i<MAXN;i++)
		jc[i]=(jc[i-1]*i)%MOD;
	Inv[MAXN-1]=ksm(jc[MAXN-1],MOD-2);
	for(long long i=MAXN-2;i>=0;i--)
		Inv[i]=(Inv[i+1]*(i+1))%MOD;
}
long long C(long long m,long long n)
{
	if(n>m)
		return 0;
	return ((jc[m]*Inv[n])%MOD*Inv[m-n])%MOD;
}
int main()
{
	//freopen("bbq.in","r",stdin);
	//freopen("bbq.out","w",stdout);
	Init();
	scanf("%lld",&n);
	long long ans=0,del=0;
	for(long long i=1;i<=n;i++)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		del=(del+C(2*(a+b),2*a))%MOD;
		dp[2000-a][2000-b]++;
		ask[2000+a][2000+b]++;
	}
	for(int i=0;i<=4000;i++)
	{
		for(int j=0;j<=4000;j++)
		{
			if(i!=0)
				dp[i][j]+=dp[i-1][j];
			if(j!=0)
				dp[i][j]+=dp[i][j-1];
			dp[i][j]%=MOD;
			ans=(ans+(ask[i][j]*dp[i][j])%MOD)%MOD;
		}
	}
	ans=(ans-del+MOD)%MOD;
	printf("%lld\n",(ans*Inv[2])%MOD);
	fclose(stdin);
	fclose(stdout);
}