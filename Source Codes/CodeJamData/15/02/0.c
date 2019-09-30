#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
  int T,t,n,maxx,i,ans,j,d;
//  freopen("1.in","r",stdin);
//  freopen("1.out","w",stdout);
  scanf("%d",&T);
  for (t=1;t<=T;t++)
  {
	scanf("%d",&n);
	maxx=0;
	for (i=1;i<=n;i++) {
	  scanf("%d",&a[i]);
	  maxx=max(maxx,a[i]);
	}
	ans=0x3f3f3f3f;
	for (i=1;i<=maxx;i++)
	{
	  d=0;
	  for (j=1;j<=n;j++)
		d+=(a[j]-1)/i;
	  ans=min(ans,d+i);
	}
	printf("Case #%d: %d\n",t,ans);
  }
}
