#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	char str[100];
	scanf("%s",str);
	printf("%c%d%c\n", str[0],strlen(str) - 2,str[strlen(str) - 1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
  printf("%c%d%c\n", str[0],strlen(str) - 2,str[strlen(str) - 1]);
         ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^