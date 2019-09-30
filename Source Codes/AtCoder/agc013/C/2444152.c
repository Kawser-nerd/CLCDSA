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

int MOD(int a, int p){
	a %= p;
	return a >= 0 ? a : a + p;
}

int main(){
	int N, L, T, i;
	scanf("%d%d%d", &N, &L, &T);
	int *X = (int *)malloc(sizeof(int) * N);
	int *W = (int *)malloc(sizeof(int) * N);
	int fW1 = -1, W2num = 0;
	for(i = 0; i < N; i++){
		scanf("%d%d", &X[i], &W[i]);
		if(fW1 == -1 && W[i] == 1){
			fW1 = i;
		}
		if(W[i] == 2){
			W2num++;
		}
	}
	if(fW1 == -1){
		for(i = 0; i < N; i++){
			printf("%d\n", MOD(X[i] - T, L));
		}
		return 0;
	}
	int gap = X[fW1];
	int *X2 = (int *)malloc(sizeof(int) * N);
	int *W2 = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		X2[i] = MOD(X[MOD(i + fW1, N)] - gap, L);
		W2[i] = W[MOD(i + fW1, N)];
	}
	int *X3 = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		X3[i] = MOD(X2[i] + (W2[i] == 1 ? T : -T), L);
	}
	sort(X3, N);
	int encountcount = ((2 * T) / L) * W2num;
	for(i = 0; i < N; i++){
		if(W2[i] == 2 && X2[i] < MOD(2 * T, L)){
			encountcount++;
		}
	}
	int fW1will;
	for(i = 0; i < N; i++){
		if(X3[i] == MOD(T, L)){
			fW1will = i;
			break;
		}
	}
	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		ans[MOD(i + fW1, N)] = MOD(X3[MOD(fW1will + i - encountcount, N)] + gap, L);
	}
	for(i = 0; i < N; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &L, &T);
  ^
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &X[i], &W[i]);
   ^