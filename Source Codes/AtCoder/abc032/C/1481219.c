#include <stdio.h>

typedef struct {
	int l;
	long long v;
} dp_t;

int main(int argc, char *argv[])
{
	int i, j, N, K, s[100000];
	dp_t dp[100000] = {{0}};
	int max = 0;

	scanf("%d %d", &N, &K);
	for ( i = 0; i < N; i++ ){
		scanf("%d", &s[i]);
		if ( s[i] == 0 ){
			printf("%d\n", N);
			return 0;
		}
	}
	if ( K < s[0] ){
		dp[0].v = 1;
	} else {
		dp[0].l = 1;
		dp[0].v = s[0];
		max = 1;
	}
	for ( i = 1; i < N; i++ ){
		long long v = dp[i-1].v * s[i];
		if ( v <= K ){
			dp[i].v = v;
			dp[i].l = dp[i-1].l + 1;
			if ( dp[i].l > max ){
				max = dp[i].l;
			}
		} else {
			dp[i].v = 1;
			for ( j = i; j > 0; dp[i].l++, dp[i].v *= s[j], j-- ){
				if ( dp[i].v * s[j] > K ){
					break;
				}
			}
		}
	}
	printf("%d\n", max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &K);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &s[i]);
   ^