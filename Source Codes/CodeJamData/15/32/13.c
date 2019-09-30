#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

static long int count(size_t L, size_t S, char *T, char *U)
{
	long int c = 0;
	for (size_t i = 0; i <= S - L; i++)
		c += !memcmp(&U[i], T, L);
	return c;
}

static float solve(size_t K, size_t L, size_t S, char *A, char *T)
{
	size_t I[7];
	char U[8];
	long int sum = 0;
	long int max = 0;
	for (size_t i = 0; i < S; i++)
		U[i] = A[I[i] = 0];
	U[S] = 0;
	while (1) {
		long int c = count(L, S, T, U);
		size_t i;
		sum += c;
		if (c > max) max = c;
		for (i = 0; i < S ; i++) {
			if (++I[i] >= K) I[i] = 0;
			U[i] = A[I[i]];
			if (I[i]) break;
		}
		if (i == S) break;
	}
	return max - sum / powf(K, S);
}

int main(void) {
	int T_;
	assert(scanf("%d", &T_) == 1);
	for (int t_ = 1; t_ <= T_; t_++) {
		size_t K, L, S;
		char A[8], T[8];
		assert(scanf("%zu %zu %zu", &K, &L, &S) == 3);
		assert(scanf("%s %s", A, T) == 2);
		printf("Case #%d: %f\n", t_, solve(K, L, S, A, T));
	}
	return 0;
}
