#include <stdio.h>
#include <string.h>
int main(void){
	char s[51];
	scanf("%s", s);
	if(s[strlen(s) - 1] == 'T') puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^