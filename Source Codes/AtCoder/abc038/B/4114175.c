#include <stdio.h>

int main(void){
	int w1, w2, h1, h2;
	scanf("%d %d", &h1, &w1);
	scanf("%d %d", &h2, &w2);
	if(h1 == h2 || w1 == w2 || h1 == w2 || w1 == h2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &h1, &w1);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &h2, &w2);
  ^