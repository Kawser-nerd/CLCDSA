#include <stdio.h>
#include <stdlib.h>

#define datatype int

typedef struct {
	int w;
	int num;
}w_and_num;

//????
int compare(datatype a, datatype b){
	return a - b;
}

//??
void sort_sub(datatype *origin, int left, int right, datatype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k]) <= 0 && j < half) || k == right){
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

void sort(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
}

int main(){
	int N, N1, N2, N1pow, N2pow, M1, M2, X, i, j, k, ans = 0;
	scanf("%d%d", &N, &X);
	N1 = N / 2;
	N2 = (N + 1) / 2;
	N1pow = 1 << N1;
	N2pow = 1 << N2;
	int *w1 = (int *)malloc(sizeof(int) * N1);
	int *w2 = (int *)malloc(sizeof(int) * N2);
	int *W1 = (int *)malloc(sizeof(int) * N1pow);
	int *W2 = (int *)malloc(sizeof(int) * N2pow);
	for(i = 0; i < N1; i++){
		scanf("%d", &w1[i]);
	}
	for(i = 0; i < N2; i++){
		scanf("%d", &w2[i]);
	}
	for(i = 0; i < N1pow; i++){
		W1[i] = 0;
	}
	for(i = 0; i < N2pow; i++){
		W2[i] = 0;
	}
	for(i = 0; i < N1; i++){
		for(j = 0; (1 << i) * j < N1pow >> 1; j++){
			for(k = 0; k < (1 << i); k++){
				W1[(1 << i + 1) * j + k] += w1[i];
			}
		}
	}
	for(i = 0; i < N2; i++){
		for(j = 0; (1 << i) * j < N2pow >> 1; j++){
			for(k = 0; k < (1 << i); k++){
				W2[(1 << i + 1) * j + k] += w2[i];
			}
		}
	}
	sort(W1, N1pow);
	sort(W2, N2pow);
/*	printf("test:\n");
	for(i = 0; i < N1pow; i++){
		printf("%d ", W1[i]);
	}
	printf("\n");
	for(i = 0; i < N2pow; i++){
		printf("%d ", W2[i]);
	}
	printf("\n");
*/	w_and_num *W1s = (w_and_num *)malloc(sizeof(w_and_num) * N1pow);
	w_and_num *W2s = (w_and_num *)malloc(sizeof(w_and_num) * N2pow);
	W1s[0].w = W1[0];
	W1s[0].num = 1;
	for(i = 1, j = 0; i < N1pow; i++){
		if(W1[i] == W1s[j].w){
			W1s[j].num++;
		}
		else{
			j++;
			W1s[j].w = W1[i];
			W1s[j].num = 1;
		}
	}
	M1 = j + 1;
	W2s[0].w = W2[0];
	W2s[0].num = 1;
	for(i = 1, j = 0; i < N2pow; i++){
		if(W2[i] == W2s[j].w){
			W2s[j].num++;
		}
		else{
			j++;
			W2s[j].w = W2[i];
			W2s[j].num = 1;
		}
	}
	M2 = j + 1;
	for(i = 0, j = M2 - 1; i < M1 && j >= 0;){
		if(W1s[i].w + W2s[j].w > X){
			j--;
		}
		else if(W1s[i].w + W2s[j].w < X){
			i++;
		}
		else{
			ans += W1s[i].num * W2s[j].num;
			i++;
			j--;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:46:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &X);
  ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &w1[i]);
   ^
./Main.c:59:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &w2[i]);
   ^