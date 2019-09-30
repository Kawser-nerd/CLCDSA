#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, answer = -1, sw = 0, divider = 1;
	int *s;
	scanf("%d", &n);
	s = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", s + i);
	}
	do{
		answer++;
		divider = divider * 2;
		for (int i = 0; i < n; i++) {
			if (s[i] % divider != 0) {
				sw = 1;
				break;
			}
		}
	} while (sw == 0);
	printf("%d\n", answer);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", s + i);
   ^