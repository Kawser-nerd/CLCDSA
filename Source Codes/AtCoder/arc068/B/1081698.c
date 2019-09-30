#include <stdio.h>

int N;
int A[1000000];

int count[100000];

int main(void) {
	int i;
	int max = 0;

	int taberu = 0;
	int twocount = 0;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
		count[A[i]]++;
		if (A[i] > max) max = A[i];
	}
	for (i = 1; i <= max; i++) {
		if (count[i] >= 2) {
			if (count[i] % 2 == 0) {
				taberu += count[i] - 2;
				twocount++;
			} else {
				taberu += count[i] - 1;
			}
		}
	}
	if (twocount % 2 == 0) {
		taberu += twocount;
	} else {
		taberu += twocount + 1;
	}
	printf("%d\n", N - taberu);
	return 0;
}