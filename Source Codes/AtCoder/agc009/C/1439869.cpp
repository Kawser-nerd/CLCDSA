#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a,b,s[200000],f[200000],g[200000],mod=1000000007;
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	if(a>b)swap(a,b);
	for(int i=1;i<=n;i++)scanf("%lld",s+i);
	s[0]=-b;
	f[0]=g[0]=1;
	for(int i=2;i<n;i++)
		if(s[i+1]-s[i-1]<a){puts("0");return 0;}
	long long sf=0,sg=0,pf=0,pg=0;
	for(int i=2;i<=n;i++)
	{
		for(;pf<i-1&&s[i]-s[pf]>=a;pf++)sf=(sf+f[pf])%mod;
		for(;pg<i-1&&s[i]-s[pg]>=b;pg++)sg=(sg+g[pg])%mod;
		f[i-1]=sg;g[i-1]=sf;
		if(s[i]-s[i-1]<b)sf=0,pf=i-1;
		if(s[i]-s[i-1]<a)sg=0,pg=i-1;
		//printf("sf=%lld,sg=%lld,pf=%lld,pg=%lld\n",sf,sg,pf,pg);
	}
	for(int i=pf;i<n;i++)sf=(sf+f[i])%mod;
	for(int i=pg;i<n;i++)sg=(sg+g[i])%mod;
	printf("%lld\n",(sf+sg)%mod);
	//printf("pf=%lld,pg=%lld\n",pf,pg);
	//for(int i=0;i<=n;i++)printf("(f,g)[%d]=%lld,%lld\n",i,f[i],g[i]);
	return 0;
}