#include <stdio.h>
int main(void){
	char s[5];
	int i,n;
	scanf("%s",s);
	scanf("%d",&n);
	printf("%c%c\n",s[(n-1)/5],s[(n-1)%5]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^