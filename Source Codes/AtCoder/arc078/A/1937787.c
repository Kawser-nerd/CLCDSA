#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int N,i;
	scanf("%d",&N);
	long long int a[N],x,y,sum=0,sum1;
	
	for(i=0;i<N;i++)
	  {
	   scanf("%lld",&a[i]);
	   sum+=a[i];
      }
	
	x=a[0];
	sum1=llabs(sum-2*a[0]);
	for(i=1;i<N-1;i++)
	{
		x+=a[i];
		if(sum1>llabs(sum-2*x))
		  sum1=llabs(sum-2*x);
	}
	printf("%lld",sum1);
	
	return 0;	
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a[i]);
     ^