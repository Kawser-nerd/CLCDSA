#include <stdio.h>

#define MAXN		50

int X[MAXN], V[MAXN];

int solve(void)
{
	int N, K, B, T;
	int i, j;
	int swaps;

	scanf("%d %d %d %d", &N, &K, &B, &T);
	for (i = 0; i < N; i++)
		scanf("%d", X + i);
	for (i = 0; i < N; i++)
		scanf("%d", V + i);

	swaps = 0;
	j = 0;
	for (i = N - 1; i >= 0 && K; i--) {
		if (X[i] + V[i] * T < B) {
			/* will not get to the barn in time */
			j++;
		} else {
			/* must skip j chicks to get to the barn */
			swaps += j;
			K--;
		}
	}

	return K ? -1 : swaps;
}

int main(void)
{
	int C, testno, answer;

	scanf("%d", &C);
	for (testno = 1; testno <= C; testno++) {
		answer = solve();
		if (answer >= 0)
			printf("Case #%d: %d\n", testno, answer);
		else
			printf("Case #%d: IMPOSSIBLE\n", testno);
	}

	return 0;
}
