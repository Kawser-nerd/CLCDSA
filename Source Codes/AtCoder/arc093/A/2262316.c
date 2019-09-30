#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int N,A[100010] = {},i,j;
	int sum = 0;
	
	scanf("%d",&N);
	for (i = 1;i <= N;i++)
		scanf("%d",&A[i]);
	for (i = 1;i <= N+1;i++)
		sum += abs(A[i] - A[i-1]);
	for (i = 1;i <= N;i++) {
		int ans;
		ans = sum - abs(A[i] - A[i-1]) - abs(A[i+1] - A[i]) + abs(A[i+1] - A[i-1]);
		printf("%d\n",ans);
	}
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);
   ^