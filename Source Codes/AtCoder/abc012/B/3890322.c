#include <stdio.h>
#include <string.h>

int main(void)
{
  int N;
  scanf("%d",&N);
  int h=N/3600;
  N-=h*3600;
  int m=N/60;
 N-=m*60;
 int s=N;
 printf("%02d:%02d:%02d",h,m,s);
  
  
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^