#include <stdio.h>

int main(void)
{
	int n,i,r=0,count=0;
	scanf("%d",&n);
	int A[n];
	for(i=0;i <= n-1;i++)
		{scanf("%d",&A[i]);}
	while(r==0)
		{
		for(i=0;i <= n-1;i++)
			{r += A[i] % 2;}
		if(r==0)
			{
			count++;
			for(i=0;i <= n-1;i++)
				{A[i] /= 2;}
			}
		}
	printf("%d\n",count);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   {scanf("%d",&A[i]);}
    ^