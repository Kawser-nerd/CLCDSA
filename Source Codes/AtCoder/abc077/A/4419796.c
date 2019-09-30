#include <stdio.h>
int main(void){
	char s11[2],s12[2],s13[2],s21[2],s22[2],s23[2];
	scanf("%c%c%c\n%c%c%c",s11,s12,s13,s21,s22,s23);
	if(s11[0]==s23[0] && s12[0]==s22[0] && s13[0]==s21[0]) printf("YES\n");
	else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c%c%c\n%c%c%c",s11,s12,s13,s21,s22,s23);
  ^