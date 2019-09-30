#include<cstdio>
#include<map>
#include<cmath>
#include<algorithm>
#define MAXN 3006
#define MAXM 100006
#define INF 210000000000
using namespace std;
long long vis[MAXN],prime[MAXN],cnt,n,sum;
long long B,C,ans,last,a;
void waiting()
{
	for(long long i=2;i<MAXN;i++)
	{
		if(!vis[i]) prime[++cnt]=i;
		for(long long j=1;prime[j]*i<MAXN;j++)
		{
			vis[prime[j]*i]=1;
			if(i%prime[j]==0) break;
		}
	}
}
struct node
{
	long long b,c;
}p[MAXM];
bool cmp(node a,node b)
{
	return a.b<b.b;
}
map<long long,long long> ma,gg;
int main()
{
	//freopen("anticube.in","r",stdin);
	//freopen("anticube.out","w",stdout);
	waiting();
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		B=1;
		C=1;
		for(long long j=1;j<=cnt;j++)
		{
			sum=0;
			if(a==1) break;
			while(a%prime[j]==0)
			{
				a/=prime[j];
				sum++;
			}
			sum%=3;
			if(sum)
			{
				if(sum==1)
				{
					B*=prime[j];
					C=C*prime[j];
					C=C*prime[j];
				}
				else
				{
					C*=prime[j];
					B=B*prime[j]*prime[j];
				}
			}
		}
		if(a!=1)
		{
			long long chuizi=sqrt(a);
			if(a==chuizi*chuizi)
			{
				B*=chuizi*chuizi;
				C*=chuizi;
			}
			else
			{
				B*=a;
				C*=a*a;
			}
		}
		p[i].b=B;
		p[i].c=C;
	}
	/*for(long long i=1;i<=n;i++)
		printf("%lld ",p[i].b);
	printf("\n");
	for(long long i=1;i<=n;i++)
		printf("%lld ",p[i].c);*/
	for(long long i=1;i<=n;i++)
		ma[p[i].b]++;
	for(long long i=1;i<=n;i++)
	{
		if(gg[p[i].b]) continue;
		gg[p[i].b]=1;
		if(p[i].c==p[i].b) ans++;
		else
		{
			ans+=max(ma[p[i].b],ma[p[i].c]);
			gg[p[i].c]=1;
		}
	}
	printf("%lld",ans);
}