#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int A[N];
	int i, j;
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int former=0;
	for (i = 0; i < N; i++) {
		for (j = i+1; j < N; j++) {
			if (A[i] > A[j]) {
				int tmp;
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
//	for (i = 0; i < N; i++) {
//		printf("%d ", A[i]);
//	}
//	printf("\n");
	for (i = N-1; i >= 0; i--) {
		if ((N-1) % 2 == 0) {//N-1 is even number
			if (i % 2 == 0) {
				former += A[i];
			}
		} else {//N-1 is odd number
			if (i % 2 == 1) {
				former += A[i];
			}
		}
	}
	printf("%d\n", former);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^