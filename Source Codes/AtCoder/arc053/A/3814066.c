#include <stdio.h>

int main()
{
	int H, W;
	scanf("%d%d", &H, &W);
	int i, j, count=0;
	for (i = 0; i < W; i++) {
		for (j = 2; j <= H; j++) {
			count++;
		}
	}
	for (i = 0; i < H; i++) {
		for (j = 2; j <= W; j++) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^