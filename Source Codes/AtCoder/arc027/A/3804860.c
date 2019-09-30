#include <stdio.h>

int main()
{
	int h, m;
	scanf("%d%d", &h, &m);
	printf("%d\n", 18*60 - h*60 -m);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &h, &m);
  ^