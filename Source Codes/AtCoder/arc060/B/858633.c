#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long f(long long b, long long n) {
	if (n<b) return n;
	else return f(b,n/b)+n%b;
}

int main() {
	long long B, N, p, q, S;
	scanf("%lld%lld", &N, &S);
	if (N == S) { printf("%lld\n", N+1); return 0; }
	else {
		for (B=2LL;B<400000LL;B++) {
			if (f(B,N) == S) { printf("%lld\n", B); return 0; }
			if (B*B>N) break;
		}
		for (p=400000LL;p>0;p--) {
			if (p*p>N) continue;
			B = (N-S)/p + 1;
			if (B>1LL && f(B,N) == S) { printf("%lld\n", B); return 0; }
		}
	}

	printf("-1\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &S);
  ^