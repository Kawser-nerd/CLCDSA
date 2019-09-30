#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007LL
#define max(x,y) ((x)>(y))?(x):(y)
#define min(x,y) ((x)>(y))?(y):(x)

long long factinv[900010], fact[900010];

void factorial(void) {
	int i, j;
	long long P, Q, R, EXP;

	fact[0] = 1; factinv[0] = 1;
	for (i=1;i<=900000;i++) {
		fact[i] = fact[i-1];
		fact[i] *= i;
		fact[i] %= MOD;

		factinv[i] = factinv[i-1];
		P = 1;
		Q = i;
		EXP = 1000000005LL;
		while (EXP>0) {
			if (EXP & 1) P *= Q;
			Q *= Q;
			EXP >>= 1;
			P %= MOD;
			Q %= MOD;
		}
		factinv[i] *= P;
		factinv[i] %= MOD;
	}

}

long long comb_mod(int a, int b) {
	long long P=1;
	P = P * fact[a];
	P = P * factinv[a-b] % MOD;
	P = P * factinv[b]   % MOD;
	return P;
}

int main() {
	int i, j, K, M, N;
	long long P, Q, R, T;
	factorial();
	scanf("%d%d%d", &N, &M, &K);

	P = 0; T = 0;
	for (i=N;i<=N+M+K;i++) {
//		printf("%6d\t", i);
		Q = 1;
		R = 3;
		j = N+M+K-i;
		while (j>0) {
			if (j & 1) Q *= R;
			R *= R;
			j >>= 1;
			R %= MOD;
			Q %= MOD;
		}
//		printf("%10lld\t", Q);
		Q *= comb_mod(i-1, N-1);
		Q %= MOD;
//		printf("%10lld\t", Q);
		if (T==0) T = 1LL;
		else {
			T *= 2LL;
			if (i>N+K) T -= comb_mod(i-N-1, i-N-1-K);
			if (M<i-N) T -= comb_mod(i-N-1, M);
		}
		T %= MOD;
		if (T<0) T += MOD;
		Q *= T;
		Q %= MOD;
//		printf("%10lld\n", Q);

		P += Q;
		P %= MOD;
	}

	printf("%lld\n", P);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &K);
  ^