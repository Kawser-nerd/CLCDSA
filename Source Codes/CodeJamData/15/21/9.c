#include <stdio.h>
#include <string.h>

#define min(a, b) ( (a) < (b) ? (a) : (b) )

static int dp[1000007];

static int rev(int n) {

	int out = 0;
	int p = 1;
	int nn = n;

	while ( nn > 0 ) {
		p *= 10;
		nn /= 10;
	}

	while ( n > 0 ) {
		p /= 10;
		out += (n%10)*p;
		n /= 10;
	}

	return out;

}

int main() {

	int t, i;
	scanf("%d", &t);

	for ( i = 0; i < t; ++i ) {

		int n, j;

		scanf("%d", &n);

		memset(dp, 0, sizeof(dp));

		for ( j = 0; j < n+1; ++j )
			dp[j] = j;

		int act = 1;

		for ( j = 1; j < n+1; ++j ) {

			dp[j] = min(dp[j], act);
			act = min(act, dp[j]);

			int r = rev(j);
			if ( r > j && r < 1000007 ) {
				dp[r] = min(dp[r], act+1);
			}

			act++;

		}

		printf("Case #%d: %d\n", i+1, dp[n]);

	}

	return 0;

}
