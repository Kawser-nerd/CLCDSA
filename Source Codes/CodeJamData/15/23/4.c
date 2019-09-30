#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long d[5],h[5],m[5];
int main()
{
  int T,t,n,i;
  long long t1,t2;
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  scanf("%d",&T);
  for (t=1;t<=T;t++)
  {
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	  scanf("%lld%lld%lld",&d[i],&h[i],&m[i]);
	printf("Case #%d: ",t);
	if (n==1) printf("0\n");
	else{
	  if (m[1]<m[2]) {swap(d[1],d[2]); swap(m[1],m[2]); }
	  t1=(360-d[1])*m[1]; t2=(720-d[2])*m[2];
	  if (t1<t2) printf("0\n");
	  else printf("1\n");
	}
  }	  
}
