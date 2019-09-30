#include<stdio.h>
int main(void)
{
  long long int n,d=0,i,x=1,temp;
  scanf("%lld",&n);
  temp = n;
  while(temp != 1)
    {
      d++;
      temp /= 2;
    }
  if(d%2 == 0)
    {
      for(i=0;;i++)
	{
	  if(i%2 == 0)
	    {
	      x = x*2 + 1;
	      if(x > n)
		{
		  printf("Aoki\n");
		  return 0;
		}
	    }
	  else
	    {
	      x = x*2;
	      if(x > n)
		{
		  printf("Takahashi\n");
		  return 0;
		}
	    }
	}
    }
  else
    {
      for(i=0;;i++)
	{
	  if(i%2 == 0)
	    {
	      x = x*2;
	      if(x > n)
		{
		  printf("Aoki\n");
		  return 0;
		}
	    }
	  else
	    {
	      x = x*2 + 1;
	      if(x > n)
		{
		  printf("Takahashi\n");
		  return 0;
		}
	    }
	}
    }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^