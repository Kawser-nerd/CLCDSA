#include <stdio.h>

int main() {
	int a;

	scanf("%d",&a);

	if(a%2==1) printf("Red\n");
	else printf("Blue\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^