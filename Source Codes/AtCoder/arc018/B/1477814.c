#include <stdio.h>
#include <stdlib.h>

#define int long long

signed main(){
	int N, i, j, k, Sx2, ans = 0;
	scanf("%lld", &N);
	int *x = (int *)malloc(sizeof(int) * N);
	int *y = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &x[i], &y[i]);
	}
	for(i = 0; i < N - 2; i++){
		for(j = i + 1; j < N - 1; j++){
			for(k = j + 1; k < N; k++){
				Sx2 = (x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]);
				if(Sx2 % 2 == 0 && Sx2 != 0){
					ans++;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &x[i], &y[i]);
   ^