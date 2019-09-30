#include <stdio.h>

int main(void){
	char str[105];
	int i;
	scanf("%s", str);
	scanf("%d", &i);
	printf("%c\n", str[i - 1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &i);
  ^