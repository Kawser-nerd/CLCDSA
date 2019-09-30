#include <stdio.h>
#include <stdlib.h>

#define int long long
#define inf (int)(1e18)
#define datatype int

//????
int compare(datatype a, datatype b){
	return a - b;
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

int can_achieve(int N, int *H, int *S, int *T, int h){
	int i;
	for(i = 0; i < N; i++){
		if(h < H[i]){
			return 0;
		}
		T[i] = (h - H[i]) / S[i];
	}
	sort(T, N);
	for(i = 0; i < N; i++){
		if(T[i] < i){
			return 0;
		}
	}
	return 1;
}

signed main(){
	int N, i;
	scanf("%lld", &N);
	int *H = (int *)malloc(sizeof(int) * N);
	int *S = (int *)malloc(sizeof(int) * N);
	int *T = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &H[i], &S[i]);
	}
	int l = 0, h, r = inf;
	while(r - l > 1){
		h = (l + r) / 2;
		if(can_achieve(N, H, S, T, h) == 1){
			r = h;
		}
		else{
			l = h;
		}
	}
	printf("%lld\n", r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:60:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &H[i], &S[i]);
   ^