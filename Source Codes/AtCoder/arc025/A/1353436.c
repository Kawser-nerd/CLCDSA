#include <stdio.h>
#include <math.h>

int main ()
{
	int d[7],j[7];
	for(int i=0;i<7;i++)
	{
		scanf("%d",&d[i]);
	}
	scanf("\n");
	for(int i=0;i<7;i++)
	{
		scanf("%d",&j[i]);
	}
	scanf("\n");
	int sum;
	for(int i=0;i<7;i++)
	{
		sum+= d[i]>j[i]?d[i]:j[i];
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&d[i]);
   ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("\n");
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&j[i]);
   ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("\n");
  ^