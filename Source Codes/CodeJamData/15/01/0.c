#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
  int i,t,T,n,ans,tmp,x;
//  freopen("1.in","r",stdin);
//  freopen("1.out","w",stdout);
  scanf("%d",&T);
  for (t=1;t<=T;t++){
	scanf("%d",&n);
	ans=0; tmp=0;
	for (i=0;i<=n;i++){
	  scanf("%1d",&x);
	  if (x&&tmp<i) ans+=i-tmp,tmp=i;
	  tmp+=x;
	}
	printf("Case #%d: %d\n",t,ans);
  }
}
