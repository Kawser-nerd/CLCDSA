#include <stdio.h>


int main()
{
	int taka;
	int tashi2;
	scanf("%d %d", &taka, &tashi2);
	int x;
	if (taka > tashi2) {
		x = taka;
	}
	else if (taka < tashi2) {
		x = tashi2;
	}
	printf("%d\n", x);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &taka, &tashi2);
  ^