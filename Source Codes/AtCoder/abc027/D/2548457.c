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

signed main(){
	int N, K, i, j, ans = 0;
	char *S = (char *)malloc(sizeof(char) * 100001);
	scanf("%s", S);
	for(N = 0; S[N] != '\0'; N++){}
	int *A = (int *)malloc(sizeof(int) * N);
	A[0] = 0;
	for(i = 1, K = (S[0] == 'M' ? 1 : 0); i < N; i++){
//		printf("i = %lld\n", i);
		if(S[i] == '+'){
//			printf("test1\n");
			A[i] = A[i - 1] + 1;
		}
		else if(S[i] == '-'){
//			printf("test2\n");
			A[i] = A[i - 1] - 1;
		}
		else{
//			printf("test3\n");
			A[i] = A[i - 1];
			K++;
		}
	}
/*	printf("K = %lld\n", K);
	for(i = 0; i < N; i++){
		printf("%lld ", A[i]);
	}
	printf("\n");
*/	int *B = (int *)malloc(sizeof(int) * K);
	for(i = 0, j = 0; i < N; i++){
		if(S[i] == 'M'){
			B[j] = A[i];
			j++;
		}
	}
/*	for(i = 0; i < K; i++){
		printf("%lld ", B[i]);
	}
	printf("\n");
*/	sort(B, K);
/*	for(i = 0; i < K; i++){
		printf("%lld ", B[i]);
	}
	printf("\n");
*/	for(i = 0; i < K / 2; i++){
		ans -= B[i];
//		printf("ans[%lld] = %lld\n", i, ans);
	}
	for(i = K / 2; i < K; i++){
		ans += B[i];
//		printf("ans[%lld] = %lld\n", i, ans);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:46:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^