#include<stdio.h>
#include<stdlib.h>

int main() {
	int N;
	int *A;
	int loop;
	unsigned long long int sum = 0;

	scanf("%d", &N);
	A = malloc(sizeof(int)*N);
	for (loop = 0; loop < N; loop++)
		scanf("%d", &A[loop]);

	for (loop = 0; loop < N - 1; loop++) {
		sum += A[loop] / 2;
		if (A[loop] % 2 != 0 && A[loop + 1] != 0) {
			sum++;
			A[loop + 1]--;
		}
	}
	sum += A[N - 1] / 2;

	printf("%ld\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long unsigned int’ [-Wformat=]
  printf("%ld\n", sum);
         ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[loop]);
   ^