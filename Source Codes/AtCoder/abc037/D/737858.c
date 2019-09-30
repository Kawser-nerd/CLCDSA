#include <stdio.h>

#define MOD 1000000007

int H, W;
unsigned int a[1000][1000], dp[1000][1000]={{0}};


unsigned int search(int i, int j) {
	unsigned int r = 1;
	if (dp[i][j]>0) return dp[i][j];
	if (0<=i-1 && a[i][j] < a[i-1][j]) r += search(i-1,j);
	if (i+1<H && a[i][j] < a[i+1][j]) r += search(i+1,j);
	if (0<=j-1 && a[i][j] < a[i][j-1]) r += search(i,j-1);
	if (j+1<W && a[i][j] < a[i][j+1]) r += search(i,j+1);
	dp[i][j] = r % MOD;
	return dp[i][j];
}

int main() {
	int i, j;
	unsigned int T=0;
	scanf("%d%d", &H, &W);
	for (i=0;i<H;i++) {
		for (j=0;j<W;j++) {
			scanf("%u", &a[i][j]);
		}
	}

	for (i=0;i<H;i++) {
		for (j=0;j<W;j++) {
			search(i,j);
		}
	}

	for (i=0;i<H;i++) {
		for (j=0;j<W;j++) {
			T += dp[i][j];
			T %= MOD;
		}
	}

	printf("%u\n", T);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:26:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%u", &a[i][j]);
    ^