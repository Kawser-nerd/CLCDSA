#include<stdio.h>
int main() {
	int inp, i, j;
	scanf("%d", &inp);
	inp = 2025 - inp;

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			if (i*j == inp) {
				printf("%d x %d\n", i, j);
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &inp);
  ^