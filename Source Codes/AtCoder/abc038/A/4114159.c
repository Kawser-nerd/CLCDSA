#include <stdio.h>
#include <string.h>

int main(void){
	char str[55];
	scanf("%s", str);
	if(str[strlen(str) - 1] == 'T')
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^