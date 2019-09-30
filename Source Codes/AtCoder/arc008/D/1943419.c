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
	int N, M, M2, i, j, l, h, r;
	scanf("%lld%lld", &N, &M);
	int *p = (int *)malloc(sizeof(int) * M);
	int *p_sub = (int *)malloc(sizeof(int) * M);
	double *a = (double *)malloc(sizeof(double) * M);
	double *b = (double *)malloc(sizeof(double) * M);
	for(i = 0; i < M; i++){
		scanf("%lld%lf%lf", &p[i], &a[i], &b[i]);
		p_sub[i] = p[i];
	}
	sort(p_sub, M);
	for(i = 0; i < M; i++){
//		printf("i = %lld\n", i);
		l = -1;
		r = M;
		while(r - l > 1){
			h = (l + r) / 2;
			if(p_sub[h] < p[i]){
				l = h;
			}
			else{
				r = h;
			}
		}
		p[i] = r;
	}
	for(M2 = 2; M2 < M; M2 <<= 1){}
	double *A = (double *)malloc(sizeof(double) * (2 * M2 - 1));
	double *B = (double *)malloc(sizeof(double) * (2 * M2 - 1));
	for(i = 0; i < 2 * M2 - 1; i++){
		A[i] = 1;
		B[i] = 0;
	}
	double ans, ans_min = 1, ans_max = 1;
	for(i = 0; i < M; i++){
//		printf("i = %lld\n", i);
		j = M2 - 1 + p[i];
		A[j] = a[i];
		B[j] = b[i];
		for(j = (j - 1) / 2;; j = (j - 1) / 2){
//			printf("j = %lld\n", j);
			A[j] = A[2 * j + 2] * A[2 * j + 1];
			B[j] = A[2 * j + 2] * B[2 * j + 1] + B[2 * j + 2];
			if(j == 0){
				break;
			}
		}
/*		printf("A:\n");
		for(i = 0; i < 2 * M2 - 1; i++){
			printf("%lf  ", A[i]);
		}
		printf("\n");
		printf("B:\n");
		for(i = 0; i < 2 * M2 - 1; i++){
			printf("%lf  ", B[i]);
		}
		printf("\n");
*/		ans = A[0] + B[0];
		if(ans < ans_min){
			ans_min = ans;
		}
		if(ans > ans_max){
			ans_max = ans;
		}
	}
	printf("%.10lf\n%.10lf\n", ans_min, ans_max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lf%lf", &p[i], &a[i], &b[i]);
   ^