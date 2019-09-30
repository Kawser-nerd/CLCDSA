#include<cstdio>
#include<algorithm>
#define MAXN 106
using namespace std;
int n,a[MAXN],ans=99999999;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int j=-100;j<=100;j++)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=(j-a[i])*(j-a[i]);
		ans=min(ans,sum);
	}
	printf("%d",ans);
}