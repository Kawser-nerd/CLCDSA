#include <stdio.h>
int main(void){
	char S[6];
	int n;
	scanf("%s%d",S,&n);
	printf("%c",S[(n-1)/5]);
	printf("%c\n",S[(n-1)%5]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d",S,&n);
  ^