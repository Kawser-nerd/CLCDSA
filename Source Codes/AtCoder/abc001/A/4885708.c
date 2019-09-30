#include <stdio.h>

int main()
{
	int h1;
	int h2;
	scanf("%d",&h1);
    scanf("%d",&h2);
	printf("%d\n",h1-h2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&h1);
  ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&h2);
     ^