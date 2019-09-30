#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
  int T,t,n,maxx,s1,s2,i;
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  scanf("%d",&T);
  for (t=1;t<=T;t++){
	scanf("%d",&n);
	maxx=s1=s2=0;
	for (i=1;i<=n;i++){
	  scanf("%d",&a[i]);
	  if (i>1&&a[i-1]>a[i]) s1+=a[i-1]-a[i];
	  if (i>1)maxx=max(maxx,a[i-1]-a[i]);
	}
	for (i=1;i<n;i++){
	  s2+=min(maxx,a[i]);
	  a[i]-=maxx;
	  a[i+1]=max(a[i],a[i+1]);
	}
	printf("Case #%d: %d %d\n",t,s1,s2);
  }
  return 0;
}
