#include <stdio.h>

int main(void) {
	int H, W;
	
	scanf("%d %d", &H, &W);
	
	printf("%d\n", 2*H*W-H-W);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &H, &W);
  ^