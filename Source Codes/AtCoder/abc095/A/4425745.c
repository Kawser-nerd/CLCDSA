#include <stdio.h>
int main(void){
	char s[4];
	int value=700;
	scanf("%s",s);
	if(s[0]=='o') value+=100;
	if(s[1]=='o') value+=100;
	if(s[2]=='o') value+=100;
	printf("%d\n",value);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^