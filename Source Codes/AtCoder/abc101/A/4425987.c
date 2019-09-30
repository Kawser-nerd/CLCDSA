#include <stdio.h>
int main(void){
	char s[5];
	int i,a=0;
	scanf("%s",s);
	for(i=0;i<4;i++){
		if(s[i]=='+') a++;
		if(s[i]=='-') a--;
	}
	printf("%d\n",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^