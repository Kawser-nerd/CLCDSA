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

int main(){
	int N, i, ans = 0;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	int *B = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	sort(B, N);
	int l, h, r;
	for(i = 0; i < N; i += 2){
		l = -1;
		r = N;
		while(r - l > 1){
			h = (l + r) / 2;
			if(B[h] >= A[i]){
				r = h;
			}
			else{
				l = h;
			}
		}
		ans += r % 2;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^