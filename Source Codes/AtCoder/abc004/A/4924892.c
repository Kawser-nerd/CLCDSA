#include <stdio.h>

int main()
{
	int S;
	scanf("%d", &S);
	printf("%d\n", S*2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &S);
  ^