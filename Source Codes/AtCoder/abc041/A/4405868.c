#include <stdio.h>
int main(void){
	int i;
	char s[101];
	scanf("%s",s);
	scanf("%d",&i);
	printf("%c\n",s[i-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&i);
  ^