#include <stdio.h>

#define MAX_NUM (1000000007)

int main(void)
{
	int N, M;

	long long int ans;

	scanf("%d %d", &N, &M);

	if (N < M){
		int temp = N;
		N = M;
		M = temp;
	}

	if (N - M >= 2){
		ans = 0;
	} else {
		long long int ansN = 1;
		int i;

		for (i = 2; i <= M; i++){
			ansN *= i;
			ansN %= MAX_NUM;
		}

		ans = ansN * ansN % MAX_NUM;
		if (N > M){
			ans *= N;
		} else {
			ans *= 2;
		}

		ans %= MAX_NUM;
	}

	printf("%lld\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &M);
  ^