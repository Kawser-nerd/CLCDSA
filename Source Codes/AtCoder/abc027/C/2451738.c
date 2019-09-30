#include<stdio.h>

int main(void)
{
  long long int n,q2=0,x=1,a=0,t=0,sum,i;
  scanf("%lld",&n);
  if(n == 1 /*|| n > 1789569705*/)
    {
      printf("Aoki\n");
      return 0;
    }
  while(1)
    {
      sum = 1;
      if(a == t)
	{
	  t++;
	  for(i=0;i<t;i++)
	    {
	      sum *= 4;
	    }
	}
      else
	{
	  a++;
	  for(i=0;i<t;i++)
	    {
	      sum *= 4;
	    }
	}
      if(n > x && n <= sum+x)
	{
	  if(a != t)
	    {
	      printf("Takahashi\n");
	      return 0;
	    }
	  else
	    {
	      printf("Aoki\n");
	      return 0;
	    }
	}
      x += sum;
      //printf("%d\n",x);
    }
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^