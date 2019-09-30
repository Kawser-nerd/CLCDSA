#include<stdio.h>

int main() {
	int i, sum = 0, N, D, X;
	scanf("%d%d%d", &N, &D, &X);
	for(i = 0; i < N; ++i) {
		int j = -1, num, tmp = 0;
		scanf("%d", &num);
		while((++j)*num+1 <= D) tmp++;
		sum += tmp;
	}
	int ans = sum + X;
	printf("%d\n", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &D, &X);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &num);
   ^