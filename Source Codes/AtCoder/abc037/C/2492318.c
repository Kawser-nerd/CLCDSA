#include<stdio.h>

int main(void)
{
  long long n,k,i,ans=0,s,l;
  scanf("%lld %lld",&n,&k);
  long long a[n];
  if(n-k < k)
    {
      s = n-k; l = k;
    }
  else
    {
      s = k; l = n-k;
    }
  for(i=0;i<n;i++)
    {
      scanf("%lld",&a[i]);
      if(n == k)
	{
	  ans += a[i];
	}
      else if(i<s)
	{
	  ans += a[i]*(i+1);
	}
      else if(i>=l)
	{
	  ans += a[i]*(n-i);
	}
      else
	{
	  if(n-k >= k)
	    {
	      ans += a[i]*k;
	    }
	  else
	    {
	      ans += a[i]*(n-k+1);
	    }
	}
    }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&n,&k);
   ^
./Main.c:18:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld",&a[i]);
       ^