#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p 998244353

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

signed main(){
	int N, i, ans;
	char *S = (char *)malloc(sizeof(char) * 200001);
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){}
	N = i;
	if(N == 2){
		if(S[0] == S[1]){
			ans = 1;
		}
		else{
			ans = 2;
		}
	}
	else if(N == 3){
		if(S[0] == S[1] && S[1] == S[2]){
			ans = 1;
		}
		else if(S[0] == S[1] || S[1] == S[2]){
			ans = 6;
		}
		else if(S[0] == S[2]){
			ans = 7;
		}
		else{
			ans = 3;
		}
	}
	else{
		int f1 = 1, f2 = 1;
		for(i = 1; i < N; i++){
			if(S[i - 1] != S[i]){
				f1 = 0;
			}
			else{
				f2 = 0;
			}
		}
		if(f1 == 1){
			ans = 1;
		}
		else{
			int sum = 0;
			for(i = 0; i < N; i++){
				sum += (int)S[i] - (int)'a';
			}
			sum %= 3;
			int j, k, l, m;
			int ***dp = (int ***)malloc(sizeof(int **) * N);
			for(i = 0; i < N; i++){
				dp[i] = (int **)malloc(sizeof(int *) * 3);
				for(j = 0; j < 3; j++){
					dp[i][j] = (int *)malloc(sizeof(int) * 3);
					for(k = 0; k < 3; k++){
						dp[i][j][k] = 0;
					}
				}
			}
			for(j = 0; j < 3; j++){
				for(k = 0; k < 3; k++){
					if(j == k){
						dp[0][j][k] = 1;
					}
					else{
						dp[0][j][k] = 0;
					}
				}
			}
			for(i = 1; i < N; i++){
				for(j = 0; j < 3; j++){
					for(k = 0; k < 3; k++){
						for(l = 0; l < 3; l++){
							for(m = 0; m < 3; m++){
								if(j != l && (k + l) % 3 == m){
									dp[i][l][m] = MOD(dp[i][l][m] + dp[i - 1][j][k]);
								}
							}
						}
					}
				}
			}
			ans = MOD(f2 + power(3, N - 1) - (dp[N - 1][0][sum] + dp[N - 1][1][sum] + dp[N - 1][2][sum]));
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^