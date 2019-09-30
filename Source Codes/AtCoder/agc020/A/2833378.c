#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, a, b;
	
	scanf("%d %d %d", &n, &a, &b);
	if (n == 2)
		printf("Borys\n");
	else if (abs(a - b) % 2 == 0)
		printf("Alice\n");
	else
		printf("Borys\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &n, &a, &b);
  ^