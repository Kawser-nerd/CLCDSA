#include<stdio.h>

int main(void)
{
  long long int n,i,sum=1;
  scanf("%lld",&n);
  if(n == 1) //n=1????????
    {
      printf("Deficient\n");
      return 0;
    }
  for(i=2;i<=n;i++)
    {
      if(n / i < i) //????n???????
	{
	  break;
	}
      if(n == i * i) //i?n??????????
	{
	  sum += i;
	}
      else if(n % i == 0) //??????
	{
	  sum = sum + i + (n / i);
	}
    }
  if(sum < n) //?????
    {
      printf("Deficient\n");
    }
  else if(sum == n)
    {
      printf("Perfect\n");
    }
  else
    {
      printf("Abundant\n");
    }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^