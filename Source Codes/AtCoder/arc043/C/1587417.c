#include <stdio.h>
#include <stdlib.h>
#define datatype int
#define int long long

//????
int compare(datatype a, datatype b){
	return a - b;
}

//??
int inv_num_sub(datatype *origin, int left, int right, datatype *tmp){
	int ans = 0;
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		ans += inv_num_sub(origin, left, half, tmp);
		ans += inv_num_sub(origin, half, right, tmp);
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
				ans += k - i;
				k++;
			}
		}
	}
	return ans;
}

//i < j && a[i] > a[j] ????(i, j)??
//effect: sort???
int inv_num(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	return inv_num_sub(origin, 0, N, tmp);
}

//??
int half_inv_num_sub(datatype *origin, int left, int right, int rest, datatype *tmp){
	int ans = 0;
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		ans += half_inv_num_sub(origin, left, half, rest, tmp);
		ans += half_inv_num_sub(origin, half, right, rest - ans, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k]) <= 0 && j < half) || k == right || ans + k - i > rest){
				origin[i] = tmp[j];
				j++;
			}
			else{
				origin[i] = tmp[k];
				ans += k - i;
				k++;
			}
		}
	}
	return ans;
}

//i < j && a[i] > a[j] ????(i, j)??
//effect: sort???
int half_inv_num(datatype *origin, int N, int rest){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	return half_inv_num_sub(origin, 0, N, rest, tmp);
}

int main(){
	int N, i, dis;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	int *A_inv = (int *)malloc(sizeof(int) * N);
	int *B1 = (int *)malloc(sizeof(int) * N);
	int *B2 = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
		A[i]--;
		A_inv[A[i]] = i;
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &B1[i]);
		B1[i] = A_inv[B1[i] - 1];
		B2[i] = B1[i];
	}
	dis = inv_num(B1, N);
	if(dis % 2 == 1){
		printf("-1\n");
	}
	else{
		dis = half_inv_num(B2, N, dis / 2);
		for(i = 0; i < N; i++){
			printf("%lld ", A[B2[i]] + 1);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:77:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:83:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^
./Main.c:88:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &B1[i]);
   ^