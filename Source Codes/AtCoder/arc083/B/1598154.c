#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e15)
#define datatype distance

typedef struct {
	int a;
	int b;
	int d;
}distance;

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

//????
int compare(datatype a, datatype b){
	return a.d - b.d;
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

signed main(){
	int N, i, j, k, ans = 0;
	scanf("%lld", &N);
	int **A = (int **)malloc(sizeof(int *) * N);
	int **B = (int **)malloc(sizeof(int *) * N);
	distance *D = (distance *)malloc(sizeof(distance) * (N * (N - 1) / 2));
	for(i = 0, k = 0; i < N; i++){
		A[i] = (int *)malloc(sizeof(int) * N);
		B[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			scanf("%lld", &A[i][j]);
			if(i < j){
				D[k].a = i;
				D[k].b = j;
				D[k].d = A[i][j];
				k++;
			}
			if(i == j){
				B[i][j] = 0;
			}
			else{
				B[i][j] = inf;
			}
		}
	}
	sort(D, N * (N - 1) / 2);
	for(k = 0; k < N * (N - 1) / 2; k++){
		if(B[D[k].a][D[k].b] < D[k].d){
			printf("-1\n");
			return 0;
		}
		else if(B[D[k].a][D[k].b] > D[k].d){
			for(i = 0; i < N; i++){
				for(j = 0; j < N; j++){
					B[i][j] = min(B[i][j], min(B[i][D[k].a] + D[k].d + B[D[k].b][j], B[i][D[k].b] + D[k].d + B[D[k].a][j]));
					B[j][i] = B[i][j];
				}
			}
			ans += D[k].d;
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:65:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld", &A[i][j]);
    ^