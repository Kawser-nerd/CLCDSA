#include <stdio.h>
int main(void){
	char s[4];
	scanf("%s",s);
	if(s[0]!=s[1] && s[1]!=s[2] && s[2]!=s[0]) printf("Yes\n");
	else printf("No\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^