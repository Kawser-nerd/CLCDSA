#include <stdio.h>
int main(void){
	char s[101];
	scanf("AtCoder%sContest",s);
	printf("A%cC\n",s[0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("AtCoder%sContest",s);
  ^