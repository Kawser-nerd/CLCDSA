#include"iostream"
#include"algorithm"
#include"stdio.h"
using namespace std;
const int Maxn = 100005;
int a[Maxn],f[Maxn][10];
int main()
{
//	freopen("text.in","r",stdin);
	int n,maxn=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[1][0]=1;//,f[1][1]=1,f[1][2]=1;
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1]) f[i][0]=f[i-1][0]+1,f[i][1]=f[i-1][1]+1,f[i][2]=f[i-1][2]+1;
		else if(a[i]-a[i-1]==1) f[i][2]=f[i-1][1]+1,f[i][1]=f[i-1][0]+1,f[i][0]=1;
		else if(a[i]-a[i-1]==2) f[i][2]=f[i-1][0]+1,f[i][0]=1;
		else f[i][0]=1;//,f[i][1]=1,f[i][2]=1;
	for(int i=1;i<=n;i++)maxn=max(maxn,max(f[i][0],max(f[i][1],f[i][2])));
	printf("%d",maxn);
	return 0;
}