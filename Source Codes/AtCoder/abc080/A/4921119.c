#include<stdio.h>
int main()
{
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	
	if(N*A < B)
	{
		printf("%d\n", N*A);
	}
	else
	{
		printf("%d\n", B);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &A, &B);
  ^