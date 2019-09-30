#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	printf("1");
	for (int i = 1; i < N; ++i)	printf("0");
	printf("7\n");	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^