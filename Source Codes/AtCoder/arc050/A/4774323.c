#include<stdio.h>

int main(){
	char s,t;
	scanf("%c %c",&s,&t);
	if(s-'A'==t-'a')puts("Yes");
	else puts("No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&s,&t);
  ^