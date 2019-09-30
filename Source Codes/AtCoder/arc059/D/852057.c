#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007LL

long long dp[5010][5010] = {{0}};

int main() {
	int i, j, len, N;
	long long exp, prod, t;
	char s[5010];
	scanf("%d%s", &N, &s);
	len = strlen(s);

	dp[0][0] = 1;
	dp[1][0] = 1; dp[1][1] = 2;
	for (i=2;i<=N;i++) {
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
		for (j=1;j<i-1;j++) {
			dp[i][j] = (2*dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
		}
		dp[i][i-1] = (2*dp[i-1][i-2]) % MOD;
		dp[i][i]   = (2*dp[i-1][i-1]) % MOD;
	}
//	for (i=0;i<=N;i++) {for (j=0;j<=i;j++) printf("%lld\t", dp[i][j]); printf("\n");}

	exp = MOD - 1 - len;
	prod = 1LL;
	t = 2LL;
	while (exp) {
		if (exp & 1) prod = (prod*t) % MOD;
		t = (t*t) % MOD;
		exp >>= 1;
	}
//	printf("2^(%lld) = %lld\n", MOD - 1 - len, prod);

	printf("%lld\n", (dp[N][len]*prod)%MOD);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[5010]’ [-Wformat=]
  scanf("%d%s", &N, &s);
        ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s", &N, &s);
  ^