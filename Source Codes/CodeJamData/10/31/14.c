#include <stdio.h>

static int get_T(void)
{
	char buf[80];

	fgets(buf, 80, stdin);

	return atoi(buf);
}

static int A[1000], B[1000];

static int check(int n, int m)
{
	if (A[n] > A[m]) {
		if (B[n] < B[m])
			return 1;
	} else {
		if (B[n] > B[m])
			return 1;
	}
	return 0;
}

static void solve(int x)
{
	char buf[256];
	int i, N;
	int n, m;
	int y;

	fgets(buf, 256, stdin);
	sscanf(buf, "%d", &N);
	for (i = 0; i < N; i++) {
		fgets(buf, 256, stdin);
		sscanf(buf, "%d %d", &A[i], &B[i]);
	}

	y = 0;
	if (N == 1)
		goto out;

	for (n = 0; n < N - 1; n++) {
		for (m = n + 1; m < N; m++)
			y += check(n, m);
	}
out:
	printf("Case #%d: %d\n", x, y);
}

int main(int argc, char **argv)
{
	int i, T;

	T = get_T();
	for (i = 1; i <= T; i++)
		solve(i);

	return 0;
}
