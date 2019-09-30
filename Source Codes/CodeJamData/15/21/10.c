#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int res(int x)
{
  int tmp=0;
  while (x)
  {
	tmp=tmp*10+x%10;
	x/=10;
  }
  return tmp;
}
int vis[1000005];
int main()
{
 freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int T,i,tmp,n;
  scanf("%d",&T);
  for (int t=1;t<=T;t++)
  {
	scanf("%d",&n);
	memset(vis,0x3f,sizeof(vis));
	vis[1]=1;
	for (i=1;i<=n;i++)
	{
	  vis[i+1]=min(vis[i]+1,vis[i+1]);
	  tmp=res(i);
	  vis[tmp]=min(vis[i]+1,vis[tmp]);
	}
	printf("Case #%d: %d\n",t,vis[n]);
  }
  return 0;
}
