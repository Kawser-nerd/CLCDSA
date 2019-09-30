#include<stdio.h>
int main(void) {
	int a;
	int i;
	scanf("%d", &a);
	for (i = 1; i < 10; i++) {
		if (i * 111 >= a)
			break;
	}
	printf("%d", i * 111);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &a);
  ^