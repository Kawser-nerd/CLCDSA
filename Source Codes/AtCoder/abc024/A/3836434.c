#include <stdio.h>

int main()
{
	int A, B, C, K, S, T;
	scanf("%d%d%d%d%d%d", &A, &B, &C, &K, &S, &T);
	if (S + T < K) {
		printf("%d\n", A*S+B*T);
	} else {
		printf("%d\n", A*S+B*T-C*(S+T));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d%d", &A, &B, &C, &K, &S, &T);
  ^