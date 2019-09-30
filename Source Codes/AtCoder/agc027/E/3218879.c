#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

char s[100002];

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

signed main(){
	int N, i, j, f;
	scanf("%s", &s[1]);
	for(N = 0; s[N + 1] != '\0'; N++){}
	for(i = 1, f = 1; i < N; i++){
		if(s[i] == s[i + 1]){
			f = 0;
			break;
		}
	}
	if(f == 1){
		printf("1\n");
		return 0;
	}
	int *A = (int *)malloc(sizeof(int) * (N + 1));
	A[0] = 0;
	for(i = 1; i <= N; i++){
		if(s[i] == 'a'){
			A[i] = (A[i - 1] + 1) % 3;
		}
		else{
			A[i] = (A[i - 1] + 2) % 3;
		}
	}
	int **dp1 = (int **)malloc(sizeof(int *) * (N + 1));
	int **dp2 = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		dp1[i] = (int *)malloc(sizeof(int) * 3);
		dp2[i] = (int *)malloc(sizeof(int) * 3);
		for(j = 0; j < 3; j++){
			dp1[i][j] = 0;
			dp2[i][j] = 0;
		}
	}
	int pre[3] = {1, 0, 0};
	dp1[0][0] = 1;
	dp2[0][0] = 1;
	for(i = 1; i <= N; i++){
		dp1[i][A[i]] = MOD(dp2[i - 1][(A[i] + 1) % 3] + dp2[i - 1][(A[i] + 2) % 3] - pre[A[i]]);
		if(A[i] == 0){
			dp1[i][A[i]] = MOD(dp1[i][A[i]] + 1);
		}
		for(j = 0; j < 3; j++){
			dp2[i][j] = MOD(dp2[i - 1][j] + dp1[i][j]);
		}
		pre[A[i]] = dp2[i][A[i]];
	}
/*	for(i = 0; i <= N; i++){
		for(j = 0; j < 3; j++){
			printf("%lld ", dp1[i][j]);
		}
		printf("\n");
	}
*/	if(A[N] == 0){
		dp2[N][A[N]] = MOD(dp2[N][A[N]] - 1);
	}
	printf("%lld\n", dp2[N][A[N]]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &s[1]);
  ^