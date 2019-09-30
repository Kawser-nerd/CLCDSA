#include <stdio.h>
#include <stdlib.h>

#define datatype int

//????
int compare(datatype a, datatype b){
	return a - b;
}

void sort_sub(datatype *origin, int left, int right, datatype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k]) >= 0 && j < half) || k == right){
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

int digit_count(int n){
	int ans;
	for(ans = 0; n != 0; ans++){
		n >>= 1;
	}
	return ans - 1;
}

int element_count(int n){
	n = (0x55555555 & n) + (0x55555555 & (n >> 1));
	n = (0x33333333 & n) + (0x33333333 & (n >> 2));
	n = (0x0f0f0f0f & n) + (0x0f0f0f0f & (n >> 4));
	n = (0x00ff00ff & n) + (0x00ff00ff & (n >> 8));
	n = (0x0000ffff & n) + (0x0000ffff & (n >> 16));
	return n;
}

int main(){
	int N, M, P, Q, R, x, y, z, i, j;
	scanf("%d%d%d%d%d", &N, &M, &P, &Q, &R);
	int **Ztable = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		Ztable[i] = (int *)malloc(sizeof(int) * M);
		for(j = 0; j < M; j++){
			Ztable[i][j] = 0;
		}
	}
	for(i = 0; i < R; i++){
		scanf("%d%d%d", &x, &y, &z);
		Ztable[x - 1][y - 1] = z;
	}
	int powN = 1 << N;
	int **subset = (int **)malloc(sizeof(int *) * powN);
	int *digit = (int *)malloc(sizeof(int) * powN);
	for(i = 0; i < powN; i++){
		subset[i] = (int *)malloc(sizeof(int) * M);
		for(j = 0; j < M; j++){
			subset[i][j] = 0;
		}
		digit[i] = digit_count(i);
	}
	int ans = 0, sum;
	for(i = 1; i < powN; i++){
		for(j = 0; j < M; j++){
			subset[i][j] = subset[i & ((1 << digit[i]) - 1)][j] + Ztable[digit[i]][j];
		}
	}
	for(i = 1; i < powN; i++){
		if(element_count(i) == P){
			sum = 0;
			sort(subset[i], M);
			for(j = 0; j < Q; j++){
				sum += subset[i][j];
			}
			if(ans < sum){
				ans = sum;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d", &N, &M, &P, &Q, &R);
  ^
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &x, &y, &z);
   ^