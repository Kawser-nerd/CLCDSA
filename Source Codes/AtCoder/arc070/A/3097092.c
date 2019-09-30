#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int x;
int main() {
	scanf("%d", &x);

	int n = 1;
	while((n + 1) * n / 2 < x) {
		n++;
	}
	printf("%d\n", n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &x);
  ^