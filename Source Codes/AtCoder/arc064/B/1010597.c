#include<stdio.h>
#include<string.h>

int main(void){
	int l;
	char s[131072];
	scanf("%s",s);
	l = strlen(s);
	if(s[0] == s[l-1]){l++;}
	if(l%2){printf("First\n");}else{printf("Second\n");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^