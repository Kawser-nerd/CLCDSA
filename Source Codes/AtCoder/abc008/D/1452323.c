#include<stdio.h>
#include<string.h>

int W, H, N, X[33], Y[33];
int dp[33][33][33][33];

int rec(int left, int right, int top, int bottom)
{
	int ret = 0, i, res;
	if(~dp[left][right][top][bottom]) return(dp[left][right][top][bottom]);
	for(i = 0; i < N; i++) {
		if(X[left] < X[i] && X[i] < X[right] && Y[top] < Y[i] && Y[i] < Y[bottom]) {
			res = 0;
			res += rec(left, i, top, i);
			res += rec(left, i, i, bottom);
			res += rec(i, right, top, i);
			res += rec(i, right, i, bottom);
			res += X[right] - X[left];
			res += Y[bottom] - Y[top];
			res -= 3;
			if(ret < res) ret = res;
		}
	}
	dp[left][right][top][bottom] = ret;
	return(ret);
}

int main()
{
	int i;
	memset(dp, -1, sizeof(dp));
	
	scanf("%d %d", &W, &H);
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d %d", &X[i], &Y[i]);
	}

	N += 2;
	X[N - 2] = 0;
	X[N - 1] = W + 1;
	Y[N - 2] = 0;
	Y[N - 1] = H + 1;
	printf("%d\n", rec(N - 2, N - 1, N - 2, N - 1));
	return(0);
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &W, &H);
  ^
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &X[i], &Y[i]);
   ^