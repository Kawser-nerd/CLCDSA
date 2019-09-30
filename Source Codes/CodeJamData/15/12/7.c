#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define LL long long
LL a[100005],b;
LL solve(LL t)
{
  LL res=0,i;
  if (t==0) return 0;
  for (i=1;i<=b;i++)
	res+=t/a[i]+1;
  return res;
}
int main()
{
  LL T,t,n,i,l,r,mid;
 freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  scanf("%lld",&T);
  for (t=1;t<=T;t++){
	scanf("%lld%lld",&b,&n);
	for (i=1;i<=b;i++) scanf("%lld",&a[i]);
	l=1; r=1000000000000000;
	while (l<r){
	  mid=l+(r-l)/2;
	  if (l+1==r){
		if (solve(l)<n) l++;
	   break;	
	  }
	  if (solve(mid)>=n) r=mid;
	  else l=mid; 
	}
	n-=solve(l-1);
	for (i=1;i<=b;i++)
	  if (l%a[i]==0) {
		n--;
		if (n==0) break;
	  }
	printf("Case #%lld: %lld\n",t,i);
  }
  return 0;
}
