#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL n,s;

LL cal(LL n,LL b)
{
	if(b == 1) return n;
	LL res = 0;
	while(n)
	{
		res += n%b;
		n /= b;
	}
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%lld %lld",&n,&s);
	if(s > n)
	{
		puts("-1");
		return 0;
	}
	if(n == s)
	{
		printf("%lld\n",n+1);
		return 0;
	}
	for(LL i=2;i*i<= n;++i)
		if(cal(n,i) == s)
		{
			printf("%lld\n",i);
			return 0;
		}
	LL b = INF;
	for(LL i=1;i*i<=n - s;++i) if((n-s)%i==0)
	{
		if(cal(n,i+1) == s)
		{
			b = min(b,i+1);
		}
		if(cal(n,(n-s)/i+1) == s)
		{
			b = min(b,(n-s)/i+1);
		}
	}
	if(b == INF)
		puts("-1");
	else
		printf("%lld\n",b);
	return 0;
}