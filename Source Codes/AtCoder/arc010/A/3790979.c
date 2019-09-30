#include <stdio.h>

int main()
{
	int N, M, A, B;
	scanf("%d%d%d%d", &N, &M, &A, &B);
	int c[M];
	int i, flag=0;
	for (i = 0; i < M; i++) {
		scanf("%d", &c[i]);
	}
	for (i = 0; i < M; i++) {
		if (N <= A) {
			N += B;
		} 
		N -= c[i];
		if (N < 0) {
			printf("%d\n", ++i);
			flag = 1;
			break;
		}
	}
	if (flag != 1) {
		printf("complete\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &N, &M, &A, &B);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &c[i]);
   ^