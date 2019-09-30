#include <stdio.h>
#include <stdlib.h>
#define inv_num_valtype int
#define int long long

//????
int compare(inv_num_valtype a, inv_num_valtype b){
	return a - b;
}

//??
int inv_num_sub(inv_num_valtype *origin, int left, int right, inv_num_valtype *tmp){
	int ans = 0;
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		ans += inv_num_sub(origin, left, half, tmp);
		ans += inv_num_sub(origin, half, right, tmp);
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
				ans += k - i;
				k++;
			}
		}
	}
	return ans;
}

//i < j && a[i] > a[j] ????(i, j)??
//effect: sort???
int inv_num(inv_num_valtype *origin, int N){
	inv_num_valtype *tmp = (inv_num_valtype *)malloc(sizeof(inv_num_valtype) * N);
	return inv_num_sub(origin, 0, N, tmp);
}

int ABS(int a){
	return a >= 0 ? a : -a;
}

signed main(){
	int N, Neven, Nodd, i;
	scanf("%lld", &N);
	int *a1 = (int *)malloc(sizeof(int) * N);
	int *a2 = (int *)malloc(sizeof(int) * N);
	int *a3 = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a1[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &a2[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &a3[i]);
	}
	Neven = (N + 1) / 2;
	Nodd = N / 2;
	int **a = (int **)malloc(sizeof(int *) * 2);
	a[0] = (int *)malloc(sizeof(int) * Neven);
	a[1] = (int *)malloc(sizeof(int) * Nodd);
	int *reverse_num = (int *)malloc(sizeof(int) * 2);
	reverse_num[0] = 0;
	reverse_num[1] = 0;
	for(i = 0; i < N; i++){
		if(a2[i] % 3 == 2 && i % 2 == (a2[i] / 3) % 2 && ABS(a2[i] - a1[i]) == 1 && ABS(a3[i] - a2[i]) == 1){
			a[i % 2][i / 2] = a2[i];
			if(a1[i] > a2[i]){
				reverse_num[i % 2]++;
			}
		}
		else{
			printf("No\n");
			return 0;
		}
	}
	if((reverse_num[0] + inv_num(a[1], Nodd)) % 2 == 0 && (reverse_num[1] + inv_num(a[0], Neven)) % 2 == 0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a1[i]);
   ^
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a2[i]);
   ^
./Main.c:64:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a3[i]);
   ^