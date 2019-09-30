#include <stdio.h>
#include <stdlib.h>

#define int long long
#define datatype int

typedef struct {
	int A;
	int num;
}pair;

//????
int compare(datatype a, datatype b){
	return b - a;
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
	int N, i, j, ans = -1;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	pair *P = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
		P[i].A = -1;
		P[i].num = 0;
	}
	sort(A, N);
	P[0].A = A[0];
	P[0].num++;
	for(i = 1, j = 0; i < N; i++){
		if(A[i] == P[j].A){
			P[j].num++;
		}
		else{
			j++;
			P[j].A = A[i];
			P[j].num++;
		}
	}
	for(i = 0; i <= j; i++){
		if(P[i].num >= 4){
			if(ans == -1){
				printf("%lld\n", P[i].A * P[i].A);
				return 0;
			}
			else{
				printf("%lld\n", ans * P[i].A);
				return 0;
			}
		}
		if(P[i].num >= 2){
			if(ans == -1){
				ans = P[i].A;
			}
			else{
				printf("%lld\n", ans * P[i].A);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^