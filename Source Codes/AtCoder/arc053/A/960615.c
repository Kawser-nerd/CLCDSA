#include <stdio.h>

int main(void)
{
	int h, w, n, m;

	scanf("%d %d", &h, &w);

	n = (w - 1) * h;
	m = (h - 1) * w;

	printf("%d\n", n + m);

	return (0);
} ./Main.c: In function �main�:
./Main.c:7:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &h, &w);
  ^