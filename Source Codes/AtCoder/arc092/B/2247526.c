#include <stdio.h>
#include <stdlib.h>
#define int long long
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

signed main(){
	int N, i, j, ans = 0, xor, bound1, bound2, bound3;
	scanf("%lld", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	int *b = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &b[i]);
	}
	for(i = 28; i >= 0; i--){
//		printf("i = %d\n", i);
		for(j = 0; j < N; j++){
			a[j] &= ((int)1 << (i + 1)) - 1;
			b[j] &= ((int)1 << (i + 1)) - 1;
		}
		sort(b, N);
/*		for(j = 0; j < N; j++){
			printf("b[%d] = %d\n", j, b[j]);
		}
*/		bound1 = 0;
		bound2 = 0;
		bound3 = 0;
		for(j = 0; j < N; j++){
			bound1 += bound(1 * ((int)1 << i) - a[j], N, b);
			bound2 += bound(2 * ((int)1 << i) - a[j], N, b);
			bound3 += bound(3 * ((int)1 << i) - a[j], N, b);
		}
//		printf("bound1 = %d\n", bound1);
//		printf("bound2 = %d\n", bound2);
//		printf("bound3 = %d\n", bound3);
		xor = (N - bound3 + bound2 - bound1) & (int)1;
//		printf("xor = %d\n", xor);
		ans |= (xor << i);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &b[i]);
   ^