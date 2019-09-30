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

int bound(int k, int N, int *b){
	int l = -1, h, r = N;
	while(r - l > 1){
		h = (l + r) / 2;
		if(b[h] < k){
			l = h;
		}
		else{
			r = h;
		}
	}
	return r;
}

int main(){
	int N, i, j, ans = 0, xor, dig, cov;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	int *b = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%d", &b[i]);
	}
	for(i = 28; i >= 0; i--){
		dig = 1 << i, cov = (dig << 1) - 1;
		xor = N & 1;
//		printf("i = %d\n", i);
		for(j = 0; j < N; j++){
			a[j] &= cov;
			b[j] &= cov;
		}
		sort(b, N);
/*		for(j = 0; j < N; j++){
			printf("b[%d] = %d\n", j, b[j]);
		}
*/		for(j = 0; j < N; j++){
			xor ^= bound(1 * dig - a[j], N, b) & 1;
			xor ^= bound(2 * dig - a[j], N, b) & 1;
			xor ^= bound(3 * dig - a[j], N, b) & 1;
		}
//		printf("xor = %d\n", xor);
		ans |= (xor << i);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:58:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:62:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &b[i]);
   ^