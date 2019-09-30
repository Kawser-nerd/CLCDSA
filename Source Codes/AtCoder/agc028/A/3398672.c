#include <stdio.h>
#include <string.h>

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
	long N, M, Slength, Tlength, min, tmp, i;
	scanf("%ld%ld%s%s", &N, &M, S, T);
	Slength = strlen(S);
	Tlength = strlen(T);
	tmp = lcm(N, M);
	//if (Slength / (tmp / N) < Tlength / (tmp / M)) min = Slength / (tmp / N);
	//else min = Tlength / (tmp / M);

	long LCM = lcm(tmp / N, tmp / M);

	for (i = 0; S[i / (tmp / N)] != '\0' && T[i / (tmp / M)] != '\0'; i += LCM) {
		if (S[i / (tmp / N)] != T[i / (tmp / M)]) {
			puts("-1");
			return 0;
		}
	}
	printf("%ld", tmp);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld%s%s", &N, &M, S, T);
  ^