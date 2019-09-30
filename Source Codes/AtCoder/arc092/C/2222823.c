#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

signed main(){
	int N, i, j, maxa = -inf, then_i, b;
	scanf("%lld", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
		if(a[i] > maxa){
			maxa = a[i];
			then_i = i;
		}
	}
	if(maxa < 0){
		printf("%lld\n", maxa);
		printf("%lld\n", N - 1);
		for(i = N; i > then_i + 1; i--){
			printf("%lld\n", i);
		}
		for(i = 1; i <= then_i; i++){
			printf("1\n");
		}
	}
	else{
		int *ans = (int *)malloc(sizeof(int) * N);
		int even_max = 0, odd_max = 0, k = 0;
		for(i = 0; i < N; i++){
			if(i % 2 == 0){
				if(a[i] >= 0){
					even_max += a[i];
				}
			}
			else{
				if(a[i] >= 0){
					odd_max += a[i];
				}
			}
		}
		if(even_max >= odd_max){
			printf("%lld\n", even_max);
			b = 0;
			for(i = 0; i < N; ){
				if(i % 2 == b && a[i] >= 0){
					break;
				}
				else{
					ans[k] = 1;
					k++;
					for(j = 1; j < N; j++){
						a[j - 1] = a[j];
					}
					N--;
					b = 1 - b;
				}
			}
			for(i = N - 1; i >= 0; i--){
				if(i % 2 == b && a[i] >= 0){
					break;
				}
				else{
					ans[k] = i + 1;
					k++;
					N--;
				}
			}
			for(i = 1; i < N; ){
				if(a[i - 1] >= 0 && a[i + 1] >= 0){
					ans[k] = 2;
					k++;
					a[0] += a[2];
					for(j = 3; j < N; j++){
						a[j - 2] = a[j];
					}
					N -= 2;
				}
				else{
					ans[k] = 3;
					k++;
					a[1] += a[3];
					for(j = 4; j < N; j++){
						a[j - 2] = a[j];
					}
					N -= 2;
				}
			}
		}
		else{
			printf("%lld\n", odd_max);
			b = 1;
			for(i = 0; i < N; ){
//				printf("b = %lld\n", b);
//				printf("a[%lld] = %lld\n", i, a[i]);
				if(i % 2 == b && a[i] >= 0){
					break;
				}
				else{
					ans[k] = 1;
					k++;
					for(j = 1; j < N; j++){
						a[j - 1] = a[j];
					}
					N--;
					b = 1 - b;
				}
			}
			for(i = N - 1; i >= 0; i--){
				if(i % 2 == b && a[i] >= 0){
					break;
				}
				else{
					ans[k] = i + 1;
					k++;
					N--;
				}
			}
			for(i = 1; i < N; ){
				if(a[i - 1] >= 0 && a[i + 1] >= 0){
					ans[k] = 2;
					k++;
					a[0] += a[2];
					for(j = 3; j < N; j++){
						a[j - 2] = a[j];
					}
					N -= 2;
				}
				else{
					ans[k] = 3;
					k++;
					a[1] += a[3];
					for(j = 4; j < N; j++){
						a[j - 2] = a[j];
					}
					N -= 2;
				}
			}
		}
		printf("%lld\n", k);
		for(i = 0; i < k; i++){
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^