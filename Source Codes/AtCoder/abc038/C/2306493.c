#include<stdio.h>

int main(void)
{
  long long int n,array[100001],i,inc=1,ans=1;
  scanf("%lld",&n);
  for(i=0;i<n;i++)
    {
      scanf("%lld",&array[i]);
    }
  for(i=0;i<n-1;i++)
    {
      if(array[i] < array[i+1])
	{
	  inc++;
	}
      else
	{
	  inc = 1;
	}
      ans += inc;
    }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:9:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld",&array[i]);
       ^