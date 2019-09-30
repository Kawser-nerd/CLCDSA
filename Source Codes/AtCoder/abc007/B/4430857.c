#include <stdio.h>
#include <string.h>
int main(void){
	char a[11];
	scanf("%s",a);
	if(strlen(a)>1) printf("a\n");
	else if(strlen(a)==1 && a[0]!='a') printf("a\n");
	else printf("-1\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",a);
  ^