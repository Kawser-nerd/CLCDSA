#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, M, L, P, Q, R, ans = 0;
	scanf("%d%d%d", &N, &M, &L);
	scanf("%d%d%d", &P, &Q, &R);
	ans = max(ans, (N / P) * (M / Q) * (L / R));
	ans = max(ans, (N / P) * (M / R) * (L / Q));
	ans = max(ans, (N / Q) * (M / P) * (L / R));
	ans = max(ans, (N / Q) * (M / R) * (L / P));
	ans = max(ans, (N / R) * (M / P) * (L / Q));
	ans = max(ans, (N / R) * (M / Q) * (L / P));
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &L);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &P, &Q, &R);
  ^