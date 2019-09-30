#include <stdio.h>
#include <stdlib.h>

#define int long long
#define inf (int)(1e18)

/*int can_achieve(int k, int *a, int N){
	int i, sum = 0;
	for(i = 0; i < N; i++){
		sum += (a[i] + k + 1) / (N + 1);
	}
	if(sum <= k){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int N, i;
	scanf("%lld", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	int l = 0, r = inf, h;
	while(r - l > 1){
		h = (l + r) / 2;
		if(can_achieve(h, a, N) == 1){
			r = h;
		}
		else{
			l = h;
		}
	}
	printf("%lld\n", r);
	return 0;
}*/

signed main(){
	int N, i, j, s, K = 0, f;
	scanf("%lld", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	for(i = 0; ; i = (i + 1) % N){
		s = a[i] / N;
		K += s;
		a[i] -= s * (N + 1);
		f = 0;
		for(j = 0; j < N; j++){
			a[j] += s;
			if(a[j] >= N){
				f = 1;
			}
		}
		if(f == 0){
			printf("%lld\n", K);
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:43:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^