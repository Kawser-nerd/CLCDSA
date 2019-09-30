#include <stdio.h>

int main(){
	int m, n, N, ans;
	scanf("%d%d%d", &m, &n, &N);
	ans = N;
	while(N >= m){
		ans += (N / m) * n;
		N = N % m + (N / m) * n;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &m, &n, &N);
  ^