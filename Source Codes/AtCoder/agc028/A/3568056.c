#include <stdio.h>

long gcd(long x, long y)
{
	return y ? gcd(y, x % y) : x;
}

long lcm(long x, long y)
{
	return x * y / gcd(x, y);
}

int main(void)
{
	char S[100001], T[100001];
	long N, M, tmp1, tmp2, i;
	scanf("%ld%ld%s%s", &N, &M, S, T);
	tmp1 = lcm(N, M);
	tmp2 = lcm(tmp1 / N, tmp1 / M);
	for (i = 0; S[i / (tmp1 / N)] != '\0' && T[i / (tmp1 / M)] != '\0'; i += tmp2) {
		if (S[i / (tmp1 / N)] != T[i / (tmp1 / M)]) {
			puts("-1");
			return 0;
		}
	}
	printf("%ld", tmp1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld%s%s", &N, &M, S, T);
  ^