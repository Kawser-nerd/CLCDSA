#include <stdio.h>
#include <stdlib.h>
#define ms_valtype int
#define inf (int)(2e9)

int min(int a, int b){
	return a <= b ? a : b;
}

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

int main(){
	int N, K, Q, i, j, k, l, ans = inf;
	scanf("%d%d%d", &N, &K, &Q);
	int *A = (int *)malloc(sizeof(int) * N);
	int *B = (int *)malloc(sizeof(int) * (N + 1));
	int *C = (int *)malloc(sizeof(int) * N);
	int *D = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	for(i = 0; i < N; i++){
//		printf("i = %d\n", i);
		B[N] = 0;
		for(j = N - 1; j >= 0; j--){
			if(A[j] < A[i]){
				B[j] = 0;
			}
			else{
				B[j] = B[j + 1] + 1;
			}
		}
//		printf("test2\n");
/*		printf("B:\n");
		for(j = 0; j < N; j++){
			printf("%d ", B[j]);
		}
		printf("\n");
*/		for(j = 0; j < N; j++){
			if(B[j] > 0){
				C[j] = A[j];
			}
			else{
				C[j] = -1;
			}
		}
		l = 0;
//		printf("test4\n");
		for(j = 0; j < N; j++){
			if(B[j] > 0){
				sort(&C[j], B[j]);
			}
			for(k = j; k <= j + B[j] - K; k++){
				D[l] = C[k];
				l++;
			}
			j += B[j];
		}
/*		printf("C:\n");
		for(j = 0; j < N; j++){
			printf("%d ", C[j]);
		}
		printf("\n");
		printf("test6\n");
*/		sort(D, l);
//		printf("l = %d\n", l);
/*		printf("D:\n");
		for(j = 0; j < l; j++){
			printf("%d ", D[j]);
		}
		printf("\n");
*/		if(l >= Q){
			ans = min(ans, D[Q - 1] - A[i]);
		}
//		printf("ans = %d\n", ans);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &K, &Q);
  ^
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^