#include <stdio.h>

int main(void)
{
  	int N, A, B;
  	scanf("%d", &N);
  	if (N == 2) {
   		scanf("%d %d", &A, &B);
  		printf("%d", A + B);
    }
  	else
      	puts("Hello World");
  	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &N);
    ^
./Main.c:8:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d %d", &A, &B);
      ^