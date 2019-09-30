#include <stdio.h>
#include <stdlib.h>
#define int long long

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, K, i, j, mul, sum, ans = 0;
	scanf("%lld%lld", &N, &K);
	int *s1 = (int *)malloc(sizeof(int) * N);
	int *s2 = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 0; i < N; i++){
		scanf("%lld", &s1[i]);
		s2[i] = 0;
	}
	s1[N] = (int)(1e9 + 1);
	s2[N] = (int)(1e9 + 1);
	for(i = 0, j = 0; i < N; i++){
		if(s1[i] == 0){
			printf("%lld\n", N);
			return 0;
		}
		else if(s1[i] > 1){
			s2[j] = s1[i];
			j++;
		}
		else{
			while(s1[i] == 1){
				i++;
				s2[j]--;
			}
			i--;
			j++;
		}
	}
	N = j;
	if(K == 0){
		printf("0\n");
		return 0;
	}
/*	for(i = 0; i < N; i++){
		printf("s2[%lld] = %lld\n", i, s2[i]);
	}
*/	for(i = 0; i < N; i++){
		mul = 1;
		sum = 0;
		for(j = i; j < N; j++){
			if(s2[j] < 0){
				sum -= s2[j];
			}
			else if(mul * s2[j] <= K){
				mul *= s2[j];
				sum++;
			}
			else{
				break;
			}
		}
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &s1[i]);
   ^