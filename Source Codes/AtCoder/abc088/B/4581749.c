#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int *s;
	int n, sum_of_alice = 0, sum_of_bob = 0;
	scanf("%d", &n);
	s = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", s + i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (s[j] < s[j + 1]) {
				swap(s + j, s + j + 1);
			}
		}
	}
	for (int i = 0; i < n; i += 2) {
		sum_of_alice += s[i];
	}
	for (int i = 1; i < n; i += 2) {
		sum_of_bob += s[i];
	}
	printf("%d\n", sum_of_alice - sum_of_bob);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", s + i);
   ^