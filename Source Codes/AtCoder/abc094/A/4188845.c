#include <stdio.h>

int main(void)
{
	int A,B,X;
	scanf("%d%d%d",&A,&B,&X);
	if(A>X) printf("NO");
	if(A<=X && B>=X-A) printf("YES");
	if(A<=X && B<X-A) printf("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&A,&B,&X);
  ^