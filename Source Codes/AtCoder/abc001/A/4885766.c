#include <stdio.h>

int main()
{
	int in1 = 0;
	int in2 = 0;
	scanf("%d%d", &in1, &in2);
	printf("%d\n",in1-in2);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &in1, &in2);
  ^