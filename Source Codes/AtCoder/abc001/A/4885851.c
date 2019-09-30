#include <stdio.h>

int main(void)
{
	int H1, H2;
		
		scanf("%d", &H1);
		scanf("%d", &H2);

		printf("%d\n", H1 - H2 );
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &H1);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &H2);
   ^