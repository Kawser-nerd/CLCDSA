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

int main(){
	int N, i;
	scanf("%d", &N);
	int *X = (int *)malloc(sizeof(int) * N);
	int *X_sub = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &X[i]);
		X_sub[i] = X[i];
	}
	sort(X_sub, N);
	for(i = 0; i < N; i++){
		if(X[i] <= X_sub[N / 2 - 1]){
			printf("%d\n", X_sub[N / 2]);
		}
		else{
			printf("%d\n", X_sub[N / 2 - 1]);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &X[i]);
   ^