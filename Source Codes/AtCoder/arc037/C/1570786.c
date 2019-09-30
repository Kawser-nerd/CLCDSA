#include <stdio.h>
#include <stdlib.h>
#define int long long
#define datatype int
#define inf (int)(1e18) + 1

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

int less_than(int *a, int *b, int N, int x){
	int i, l, h, r, ans = 0;
	for(i = 0; i < N; i++){
		l = -1;
		r = N;
		while(r - l > 1){
			h = (l + r) / 2;
			if(x <= a[i] * b[h]){
				r = h;
			}
			else{
				l = h;
			}
		}
		ans += r;
	}
	return ans;
}

signed main(){
	int N, K, i;
	scanf("%lld%lld", &N, &K);
	int *a = (int *)malloc(sizeof(int) * N);
	int *b = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &b[i]);
	}
	sort(a, N);
	sort(b, N);
	int l = 0, h, r = inf + 1;
	while(r - l > 1){
		h = (l + r) / 2;
		if(less_than(a, b, N, h) < K){
			l = h;
		}
		else{
			r = h;
		}
	}
	printf("%lld\n", l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^
./Main.c:68:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &b[i]);
   ^