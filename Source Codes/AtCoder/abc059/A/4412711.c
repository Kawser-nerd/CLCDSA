#include <stdio.h>
int main(void){
	char s1[11],s2[11],s3[11];
	scanf("%s%s%s",s1,s2,s3);
	printf("%c%c%c\n",s1[0]-32,s2[0]-32,s3[0]-32);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s%s",s1,s2,s3);
  ^