#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	char str[100000];
	scanf("%s",str);
	for (int i = 0; i < strlen(str); i += 2)
	{
		printf("%c",str[i]);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^