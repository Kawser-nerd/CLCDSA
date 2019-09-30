#include <stdio.h>

int main(){
	char like[10];
	int n;
	scanf("%s", like);
	scanf("%d", &n);
	n--;
	printf("%c%c\n", like[n / 5], like[n % 5]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", like);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^