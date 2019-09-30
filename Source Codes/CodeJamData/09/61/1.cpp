#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 50 + 5;

int g[maxn][maxn];
int n,m;
long long gcd( long long a,long long b )
{
	if(b==0) return a;else
		return gcd(b,a%b);
}
int main()
{
	int T;
	scanf("%d",&T);
	long long ans,ans2,tmp,ans3;
	for(int num=1;num<=T;num++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",g[i]);
			g[i][1] = 1;
			for(int j=2;j<=g[i][0];j++)
				scanf("%d",g[i]+j);
		}

		ans2 = n;ans2 = ans2*ans2;
		ans = 0;ans3 = 0;

		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		for(int u=1;u<=g[i][0];u++)
		for(int v=1;v<=g[j][0];v++) if( i!=j || u==v )
		{
			tmp =  n+1-max(g[i][u],g[j][v]);
			if(tmp<0) continue;
			if( i==j ) tmp=tmp*n;
			ans+=tmp;
			ans3+= (ans/ans2);
			ans%=ans2;
		}

		if( ans==0 ) ans2=1;else
		{
			long long g = gcd(ans,ans2);
			ans/=g;ans2/=g;
		}
		printf("Case #%d: %I64d+%I64d/%I64d\n",num,ans3,ans,ans2);
	}
	return 0;
}
