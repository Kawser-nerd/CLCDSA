#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, T, i;
	scanf("%d%d", &N, &T);
	int *t = (int *)malloc(sizeof(int) * N);
	long long int ans = T;
	for(i = 0; i < N; i++){
		scanf("%d", &t[i]);
	}
	for(i = 1; i < N; i++){
		if(t[i] - t[i - 1] > T){
			ans += T;
		}
		else{
			ans += t[i] - t[i - 1];
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &T);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &t[i]);
   ^