#include <stdio.h>

int main(){
	int in;
	scanf("%d", &in);
	if(in == 1)
		printf("ABC\n");
	else
		printf("chokudai\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &in);
  ^