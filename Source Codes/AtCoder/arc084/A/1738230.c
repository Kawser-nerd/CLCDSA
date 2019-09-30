#include <stdio.h>
#include <stdlib.h>
#define int long long
#define ms_valtype int

//????
int compare(ms_valtype a, ms_valtype b){
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
			else if(compare(tmp[j], tmp[k]) <= 0 && j < half){
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

int main(){
	int N, i, j, ans = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	int *B = (int *)malloc(sizeof(int) * N);
	int *C = (int *)malloc(sizeof(int) * N);
	int *a = (int *)malloc(sizeof(int) * N);
	int *b = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &B[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &C[i]);
	}
	sort(A, N);
	sort(B, N);
	sort(C, N);
	for(i = 0, j = 0; i < N; i++){
		while(B[i] >= C[j] && j < N){
			j++;
		}
		b[i] = N - j;
	}
/*	for(i = 0; i < N; i++){
		printf("%lld  ", b[i]);
	}
	printf("\n");
*/	for(j = N - 2; j >= 0; j--){
		b[j] += b[j + 1];
	}
/*	for(i = 0; i < N; i++){
		printf("%lld  ", b[i]);
	}
	printf("\n");
*/	for(i = 0, j = 0; i < N; i++){
		while(A[i] >= B[j] && j < N){
			j++;
		}
		if(j < N){
			ans += b[j];
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &B[i]);
   ^
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &C[i]);
   ^