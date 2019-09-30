#include <stdio.h>
#include <stdlib.h>

long combination(long int n, long int k) {
	if (n < k)return 0;
	if (k > 0) {
		return combination(n, k - 1) * (n - k + 1) / k;
	}
	else {
		return 1;
	}
}

int func(const void *a, const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;
	if (*A > *B) return 1;
	if (*A < *B) return -1;
	return 0;
}

int main(void) {
	long int N;
	long S[200001];
	long sorted[200001];
	scanf("%ld", &N);
	S[0] = 0;
	for (long int i = 1; i <= N; i++) {
		long temp;
		scanf("%ld", &temp);
		S[i] = S[i - 1] + temp;
	}
	long max = -10000000;
	for (int i = 1; i <= N; i++) {
		if (max < S[i])max = S[i];
	}
	//counting_sort(S, sorted, max, N + 1);
	qsort(S, N + 1, sizeof(long), func);
	long int before = 1;
	long int res = 0;
	for (long int i = 1; i <= N; i++) {
		if (S[i] == S[i - 1]) {
			before++;
		}
		else {
			res += combination(before, 2);
			before = 1;
		}
	}
	res += combination(before, 2);
	printf("%ld\n", res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &N);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &temp);
   ^