#include <stdio.h>
int main(void){
	char a[2],b[2];
	scanf("%s %s",a,b);
	if(a[0]=='H'){
		if(b[0]=='H') printf("H\n");
		else printf("D\n");
	}
	else{
		if(b[0]=='H') printf("D\n");
		else printf("H\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s",a,b);
  ^