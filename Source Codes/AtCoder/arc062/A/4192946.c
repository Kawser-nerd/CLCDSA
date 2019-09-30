#include<stdio.h>

#define MAX(a,b)(a>b?a:b)

int main() {
	long long N, T, A;
	long long nowT, nowA, coef;
	scanf("%lld", &N);
	scanf("%lld%lld", &T, &A);
	while (--N) {
		scanf("%lld%lld", &nowT, &nowA);
		if (T%nowT != 0) { T += nowT - T%nowT; }
		if (A%nowA != 0) { A += nowA - A%nowA; }
		coef = MAX(T / nowT, A / nowA);
		T = nowT * coef;
		A = nowA * coef;
	}
	printf("%lld\n", T + A);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &T, &A);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &nowT, &nowA);
   ^