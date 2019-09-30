#include <stdio.h>

int main(){
	int in;
	scanf("%d\n", &in);
	printf("%d\n", in / 10 + in % 10);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n", &in);
  ^