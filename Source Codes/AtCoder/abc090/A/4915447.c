#include <stdio.h>
int main(void){
	char s[3][4];
	scanf("%s",s[0]);
	scanf("%s",s[1]);
	scanf("%s",s[2]);
	printf("%c%c%c",s[0][0],s[1][1],s[2][2]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s[0]);
  ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s[1]);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s[2]);
  ^