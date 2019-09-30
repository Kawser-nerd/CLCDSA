#include <stdio.h>
#define MOD 1000000007

int N;
char S1[53], S2[53];

int main(void) {
	int i;
	long long int ans;
	scanf("%d%s%s", &N, S1, S2);

	if (S1[0] == S2[0]) {
		ans = 3;
		i = 1;
	}
	else {
		ans = 6;
		i = 2;
	}

	for (; i < N; i++) {
		if (S1[i] == S2[i] && S1[i - 1] == S2[i - 1])
			ans = ans * 2 % MOD;
		else if (S1[i] == S2[i] && S1[i - 1] != S2[i - 1])
			;
		else if (S1[i] != S2[i] && S1[i - 1] == S2[i - 1]) {
			ans = ans * 2 % MOD;
			i++;
		}
		else if (S1[i] != S2[i] && S1[i - 1] != S2[i - 1]) {
			ans = ans * 3 % MOD;
			i++;
		}
	}
	printf("%lld", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s%s", &N, S1, S2);
  ^