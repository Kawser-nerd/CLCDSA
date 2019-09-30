#include <stdio.h>
int main(void){
	char s[10];
	int i,a;
	scanf("%s",s);
	scanf("%d",&a);
	printf("%c%c\n",s[(a-1)/5],s[(a-1)%5]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^