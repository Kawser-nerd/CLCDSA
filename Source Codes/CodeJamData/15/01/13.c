#include<stdio.h>
#define ll long long
int main()
{
  ll int t,j=1,smax,cur,i,ans;
  char arr[10001];

  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&smax);
    scanf("%s",arr);
    cur=0;
    ans=0;
    cur+=arr[0]-48;
    for(i=1;i<=smax;i++)
    {
      if(arr[i]!=48)
        if(cur<i)
        {
          ans+=i-cur;
          cur=i+arr[i]-48;
        }
        else
          cur+=arr[i]-48;
    }
    printf("Case #%lld: %lld\n",j++,ans);
   }

   return 0;
   }
