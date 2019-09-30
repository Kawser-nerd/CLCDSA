#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=1000010;
int n,pr[MAXN],sum=0;
bool pd[MAXN];
void prime()
{
	pd[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(pd[i]==0)
		{
			pr[++sum]=i;
		}
		for(int j=1;j<=sum;j++)
		{
			if(pr[j]*i>n) break;
			pd[ i * pr[j] ]=1;
			if( ! i % pr[j] ) break;
		} 
	}
}
int main()
{
	scanf("%d",&n);
	prime();
	if(pd[n]==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}