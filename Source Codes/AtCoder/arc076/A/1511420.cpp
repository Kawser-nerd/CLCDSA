#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,mod=1000000007;
int fac(int x)
{
	int ans=1;
	for(int i=2;i<=x;i++)ans=ans*i%mod;
	return ans;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	if(n<m)swap(n,m);
	if(n-m>1){puts("0");return 0;}
	if(n==m)printf("%lld\n",2*fac(n)*fac(m)%mod);
	else printf("%lld\n",fac(n)*fac(m)%mod);
	return 0;
}