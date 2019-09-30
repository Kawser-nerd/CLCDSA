#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long 

int main(int argc, char const *argv[]){
	char str[24];
	scanf("%s",str);
	str[6 - 1] = ' ';
  	str[14 - 1] = ' ';
  	printf("%s",&str);
} ./Main.c: In function ‘main’:
./Main.c:15:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[24]’ [-Wformat=]
    printf("%s",&str);
           ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^