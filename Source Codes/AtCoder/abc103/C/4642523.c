#include<stdio.h>

int main()
{
	int N = 0;
	scanf("%d", &N);
	long sum = 0;
	for(int i = 0; i < N; i++)
	{
		int j = 0;
		scanf("%d", &j);
		sum += j - 1;
	}
	printf("%ld\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &j);
   ^