#include <stdio.h>

int N, K;
int A[1000000];

int main(void) {
	int i;
	int asumisu, mizuhasu;
	if (scanf("%d%d", &N, &K) != 2) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	asumisu = N - K;
	mizuhasu = K - 1;
	printf("%d\n", (asumisu + mizuhasu - 1) / mizuhasu + 1); /* +1 : ?? */
	return 0;
}

/*
?????????????
?????????????
??????K
??????K-1
*/