#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, a, b;
	int dist;

	scanf("%d %d %d", &n, &a, &b);

	dist = abs(a - b);
	if (dist & 1) {
		puts("Borys");
	} else {
		puts("Alice");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &n, &a, &b);
  ^