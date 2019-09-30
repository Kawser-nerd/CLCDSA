#include <stdio.h>

#define BUILD_TABLE	0
#define MODULO		100003
#define MAXN		500

int invmul[MODULO + 1];
int npure[MAXN + 1][MAXN + 1];
int take[MAXN + 1][MAXN + 1];

void euclidext(int a, int b, int *x, int *y)
{
	int x0, y0;
	if (!b) {
		*x = 1;
		*y = 0;
	} else {
		euclidext(b, a % b, &x0, &y0);
		*x = y0;
		*y = x0 - (a / b) * y0;
	}
}

int computeinv(int n)
{
	int x, y;

	if (invmul[n])
		return invmul[n];

	euclidext(n, MODULO, &x, &y);
	if (x <= 0)
		x = MODULO + x % MODULO;

	return (invmul[n] = x);
}

int computetake(int n, int k)
{
	if (!k || n == k)
		return 1;
	if (take[n][k])
		return take[n][k];
	return (take[n][k] = (computetake(n - 1, k - 1) + computetake(n - 1, k)) % MODULO);
}

int computenpure(int n, int m)
{
	long long answer;
	int i;

	if (m == 1)
		return 1;
	if (m == n - 1)
		return 1;
	if (npure[n][m])
		return npure[n][m];

	answer = 0;
	i = 2 * m - n;
	if (i < 1)
		i = 1;
	for ( ; i < m; i++)
		answer = (answer + (long long) computenpure(m, i) * (long long) computetake(n - m - 1, m - i - 1)) % MODULO;

	return (npure[n][m] = (int) answer);
}

int solve(void)
{
	int n, i;
	int answer;

	scanf("%d", &n);

	answer = 0;
	for (i = 1; i < n; i++)
		answer = (answer + computenpure(n, i)) % MODULO;

	return answer;
}

int main(void)
{
	int T, testno;

	scanf("%d", &T);
	for (testno = 1; testno <= T; testno++)
		printf("Case #%d: %d\n", testno, solve());

	return 0;
}
