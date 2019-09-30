#include <stdio.h>
#include <string.h>

int main(){
	char a[55], b[55];
	scanf("%s", a);
	scanf("%s", b);
	if(strlen(a) > strlen(b))
		printf("%s\n", a);
	else
		printf("%s\n", b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", a);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", b);
  ^