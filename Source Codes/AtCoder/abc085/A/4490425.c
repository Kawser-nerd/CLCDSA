#include<stdio.h>
 
int main(void) {
	char S[10];
	scanf("%s", S);
	S[3] = '8';
	printf("%s", S);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^