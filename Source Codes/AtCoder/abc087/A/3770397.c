#include <stdio.h>

int main()
{
	int money, cake, donut;
  	scanf("%d%d%d", &money, &cake, &donut);
  	money -= cake;
  	printf("%d", money % donut);
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d", &money, &cake, &donut);
    ^