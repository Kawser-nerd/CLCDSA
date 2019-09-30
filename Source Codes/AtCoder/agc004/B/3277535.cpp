#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 2000
#define LL long long
#define INF 1000000000000000000
int n;
LL a[MAXN+5],x;
LL minn[MAXN+5];
LL ans;
int main()
{
	ans=INF;
	scanf("%d%lld",&n,&x);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	memset(minn,0x3f,sizeof(minn));
	for(LL st=0;st<n;st++)
	{
		LL sum=0;
		for(LL j=0;j<=n-1;j++)
		{
			minn[j]=min(minn[j],a[(j-st+n)%n]);
			sum+=minn[j];
		}
		ans=min(ans,sum+st*x);
	}
	printf("%lld",ans);
}