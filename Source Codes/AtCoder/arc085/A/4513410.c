#include<stdio.h>
#include<math.h>
int main() {
	int N, M;
	int ans;
	scanf("%d%d",&N, &M);
	ans = (1900 * M + 100*(N - M))*(int)pow(2,(double)M);
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N, &M);
  ^