#include<stdio.h>
int main(void) {
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
 
	if(A+B>C+D) printf("Left\n");
	else if(A+B<C+D) printf("Right\n");
	else printf("Balanced\n");
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &A, &B, &C, &D);
  ^