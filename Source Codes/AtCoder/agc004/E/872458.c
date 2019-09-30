#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x,y) ((x)>=(y))?(y):(x)
#define max(x,y) ((x)<=(y))?(y):(x)

int dp[110][110][110][110] = {0};
int row[110][110] = {0};
int col[110][110] = {0};

int main() {
	int d, down, H, i, j, k, l, left, r, right, u, up, W, x, y; 
	char a[110][110];
	scanf("%d%d", &H, &W);
	for (i=0;i<H;i++) scanf("%s", &a[i]);

	for (i=0;i<H;i++) { for (j=0;j<W;j++) {
		if (a[i][j] == 'E') {
			x = j; y = i;
		}
	} }
//	printf("Exit: %d %d\n", y, x);

	for (j=0;j<=W;j++) col[0][j] = 0;
	for (i=1;i<=H;i++) for (j=1;j<=W;j++) {
		col[i][j] = col[i-1][j] + (a[i-1][j-1] == 'o');
	}
	for (i=0;i<=H;i++) row[i][0] = 0;
	for (i=1;i<=H;i++) for (j=1;j<=W;j++) {
		row[i][j] = row[i][j-1] + (a[i-1][j-1] == 'o');
	}

	dp[0][0][0][0] = 0;
	for (l=0;l<=x;l++) { for (u=0;u<=y;u++) { for (r=0;r<W-x;r++) { for (d=0;d<H-y;d++) {
//		printf("%d %d %d %d\n", l, u, r, d);
		up = max(y-u,d);
		down = min(y+d,H-u-1);
		left = max(x-l,r);
		right = min(x+r,W-l-1);
//		printf("%d %d %d %d\n", up, down, left, right);
		if (l+1 <= x && l+r < x) dp[l+1][u][r][d] = max(dp[l][u][r][d] + col[down+1][x-l] - col[up][x-l], dp[l+1][u][r][d]);
		else dp[l+1][u][r][d] = max(dp[l][u][r][d], dp[l+1][u][r][d]);
//		printf("dp[%d][%d][%d][%d] = %d\n", l+1, u, r, d, dp[l+1][u][r][d]);
		if (u+1 <= y && u+d < y) dp[l][u+1][r][d] = max(dp[l][u][r][d] + row[y-u][right+1] - row[y-u][left], dp[l][u+1][r][d]);
		else dp[l][u+1][r][d] = max(dp[l][u][r][d], dp[l][u+1][r][d]);
//		printf("dp[%d][%d][%d][%d] = %d\n", l, u+1, r, d, dp[l][u+1][r][d]);
		if (x+r+1 < W && l+r < W-x-1) dp[l][u][r+1][d] = max(dp[l][u][r][d] + col[down+1][x+r+2] - col[up][x+r+2], dp[l][u][r+1][d]);
		else dp[l][u][r+1][d] = max(dp[l][u][r][d], dp[l][u][r+1][d]);
//		printf("dp[%d][%d][%d][%d] = %d\n", l, u, r+1, d, dp[l][u][r+1][d]);
		if (y+d+1 < H && u+d < H-y-1) dp[l][u][r][d+1] = max(dp[l][u][r][d] + row[y+d+2][right+1] - row[y+d+2][left], dp[l][u][r][d+1]);
		else dp[l][u][r][d+1] = max(dp[l][u][r][d], dp[l][u][r][d+1]);
//		printf("dp[%d][%d][%d][%d] = %d\n", l, u, r, d+1, dp[l][u][r][d+1]);
	} } } }
//	printf("dp[%d][%d][%d][%d] = %d\n", x, y, W-x-1, H-y-1, dp[x][y][W-x-1][H-y-1]);
	printf("%d\n", dp[x][y][W-x-1][H-y-1]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:26: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[110]’ [-Wformat=]
  for (i=0;i<H;i++) scanf("%s", &a[i]);
                          ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:16:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i=0;i<H;i++) scanf("%s", &a[i]);
                    ^