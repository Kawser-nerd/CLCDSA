#include<cstdio>
#include<algorithm>
using namespace std;
long long n,f[200000],mod=1000000007,a,b,s[200000];
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%lld",s+i);
	if(a>b)swap(a,b);
	for(int i=2;i<n;i++)
		if(s[i+1]-s[i-1]<a){puts("0");return 0;}
	f[0]=1;s[0]=-b;
	long long sum=0,r=0;
	for(int i=1;i<=n;i++)
	{
		for(;r<i&&s[i]-s[r]>=b;r++)sum=(sum+f[r])%mod;
		f[i]=sum;
		if(s[i]-s[i-1]<a)sum=0,r=i-1;
	}
	for(int i=r;i<=n;i++)sum=(sum+f[i])%mod;
	printf("%lld\n",sum);
	return 0;
}