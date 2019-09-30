#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x[100];
	scanf("%s", x);
	int sum=0;
	int i;
	char a[2];
	a[1] = '\0';
	for (i = 0; x[i] != '\0'; i++) {
		a[0] = x[i];
		sum += atoi(a);
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", x);
  ^