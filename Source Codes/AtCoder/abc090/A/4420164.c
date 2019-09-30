#include <stdio.h>
int main(void){
	char s1[4],s2[4],s3[4];
	scanf("%s%s%s",s1,s2,s3);
	printf("%c%c%c\n",s1[0],s2[1],s3[2]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s%s",s1,s2,s3);
  ^