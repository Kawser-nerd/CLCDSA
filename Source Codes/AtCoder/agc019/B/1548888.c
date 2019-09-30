#include <stdio.h>
#include <stdlib.h>

#define int long long
#define max_size (int)(2 * 1e5 + 1)

int main(){
	int i, j, N, ans = 1;
	char *A = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", A);
	for(i = 0; A[i] != '\0'; i++){}
	N = i;
	int **sum = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		sum[i] = (int *)malloc(sizeof(int) * 26);
		for(j = 0; j < 26; j++){
			sum[i][j] = 0;
		}
	}
	for(i = 0; i < N; i++){
		sum[i][(int)A[i] - (int)'a']++;
	}
	for(i = 1; i < N; i++){
		for(j = 0; j < 26; j++){
			sum[i][j] += sum[i - 1][j];
		}
	}
	for(i = N - 1; i >= 0; i--){
		ans += i - sum[i][(int)A[i] - (int)'a'] + 1;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", A);
  ^