#include <stdio.h>
#include <stdlib.h>
#define ms_valtype int

//????
int compare_ms(ms_valtype a, ms_valtype b){
	return a - b;
}

//??
void sort_sub(ms_valtype *origin, int left, int right, ms_valtype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare_ms(tmp[j], tmp[k]) <= 0 && j < half){
				origin[i] = tmp[j];
				j++;
			}
			else{
				origin[i] = tmp[k];
				k++;
			}
		}
	}
}

void sort(ms_valtype *origin, int N){
	ms_valtype *tmp = (ms_valtype *)malloc(sizeof(ms_valtype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, i, j, S = 0, maxj, Shalf;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
		S += A[i];
	}
	sort(A, N);
	Shalf = S / 2;
	int *dp = (int *)malloc(sizeof(int) * (Shalf + 1));
	for(j = 0; j <= Shalf; j++){
		dp[j] = 0;
	}
	dp[0] = 1;
	for(i = 0, maxj = 0; i < N; i++){
		maxj = min(maxj + A[i], Shalf);
		for(j = maxj; j >= A[i]; j--){
			dp[j] |= dp[j - A[i]];
		}
		if(dp[Shalf] == 1){
			printf("%d\n", S - Shalf);
			return 0;
		}
	}
	for(i = maxj; i >= 0; i--){
		if(dp[i] == 1){
			printf("%d\n", S - i);
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:48:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^