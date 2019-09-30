#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int N, A[100000];

int main(void) {
	int i, len[2] = {0};
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), comp);

	for (i = 0; i < N - 1; i++) {
		if (A[i] == A[i + 1]) {
			if (len[0] == 0) {
				len[0] = A[i];
			}
			else {
				len[1] = A[i];
				break;
			}
			i++;
		}
	}

	printf("%lld", (long long int)len[0] * len[1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^