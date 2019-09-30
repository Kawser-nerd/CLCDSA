#include <stdio.h>

int main(int argc, char* argv[]) {

	long x, y;
	int count = 0;
	long m;

	scanf("%ld %ld", &x, &y);

	m = x;
	while(m <= y) {
		m = m * 2;
		count++;
	}

	printf("%d", count);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld", &x, &y);
  ^