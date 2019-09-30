#include <stdio.h>
#include <stdlib.h>

int compar_int(int *a, int *b) {
	if (*a > *b) return 1;
	if (*a == *b) return 0;
	return -1;
}

int main() {
	long long int ans;
	int l[2];
	l[0] = 0; l[1] = 0;
	int N;
	scanf("%d", &N);
	int A[N];
	for (int i = 0; i < N; i++) scanf("%d", A+i);
	
	qsort(A, N, sizeof(int), compar_int);

	for (int i = N-1; i > 0 && !l[1]; i--) {
		if (A[i] == A[i-1]) {
			if (!l[0]) l[0] = A[i];
			else l[1] = A[i];
			i--;
		}
	}

	ans = (long long int)l[0] * l[1];

	printf("%lld\n", ans);

	return 0;	
} ./Main.c: In function ‘main’:
./Main.c:19:27: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(A, N, sizeof(int), compar_int);
                           ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(int *, int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:17:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i = 0; i < N; i++) scanf("%d", A+i);
                              ^