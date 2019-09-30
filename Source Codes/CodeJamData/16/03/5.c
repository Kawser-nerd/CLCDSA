#include <stdio.h>

int main() {
	int t, T;
	int N, J;
	int i, j, k;
	scanf("%d", &T);
	scanf("%d %d", &N, &J);
	printf("Case #1:\n");
	for(j = 0; j < J; j++) {
		k = j;
		printf("1");
		for(i = 0; i < (N-2)/2; i++) {
			printf("%d%d", k % 2, k % 2);
			k /= 2;
		}
		printf("1");
		for(i = 3; i <= 11; i++) {
			printf(" %d", i);
		}
		printf("\n");
	}
}
