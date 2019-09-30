#include <stdio.h>

typedef long long ll;
#define MAX 1000000007

int N, C, A[400], B[400];
ll dp[401][400] = {0};
ll pows[401][401] = {0};
ll culc(int c, int index){
	int ci, cs = 0;
	ll ret = 0, xi;
	if(index == N){ return 1; }
	if(dp[c][index]){ return dp[c][index]; }
	if(index+1 == N){ cs = c; }
	for(ci=cs; ci<=c; ci++){
		xi = (MAX + pows[B[index]][ci] - pows[A[index]-1][ci])%MAX;
		ret = (ret + (xi*culc(c-ci, index+1))%MAX)%MAX;
	}
	return dp[c][index] = ret;
}
int main(void){
	int i, j;
	scanf("%d%d", &N, &C);
	for(i=0;i<N;i++){ scanf("%d", &A[i]); }
	for(i=0;i<N;i++){ scanf("%d", &B[i]); }
	for(i=1;i<=400;i++){
		pows[i][0] = 1;
		for(j=1;j<=400;j++) pows[i][j] = (pows[i][j-1]*i)%MAX;
	}
	for(j=0;j<=400;j++){
		for(i=2;i<=400;i++){
			pows[i][j] = (pows[i][j]+pows[i-1][j])%MAX;
		}
	}
	printf("%lld\n", culc(C, 0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &C);
  ^
./Main.c:24:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++){ scanf("%d", &A[i]); }
                    ^
./Main.c:25:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++){ scanf("%d", &B[i]); }
                    ^