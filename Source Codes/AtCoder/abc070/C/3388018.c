#include <stdio.h>

long gcd(long x, long y)
{
	return y ? gcd(y, x % y) : x;
}

long lcm(__int128 x, __int128 y)
{
	return x * y / gcd(x, y);
}

int main(void)
{
	int N, i;
	long T[100];
	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%ld", &T[i]);
	for (i = 1; i < N; ++i) T[i] = lcm(T[i - 1], T[i]);
	printf("%ld", T[N - 1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:18:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < N; ++i) scanf("%ld", &T[i]);
                          ^