#include <stdio.h>
#include <string.h>

int main(){
	char a[15];
	int len;
	scanf("%s", a);
	if(a[1] == '\0' && a[0] == 'a')
		printf("-1\n");
	else
		printf("a\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", a);
  ^