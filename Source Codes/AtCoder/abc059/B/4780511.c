#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long

int main(int argc, char const *argv[]){
	int flag;
	char a[107],b[107];
	scanf("%s %s",&a,&b);
	flag = strcmp(a,b);
	if(strlen(a) == strlen(b)){
		if(flag == 0)	puts("EQUAL");
		else if(flag > 0)	puts("GREATER");
		else puts("LESS");
	}	
	else if(strlen(a) > strlen(b))	puts("GREATER");
	else puts("LESS");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[107]’ [-Wformat=]
  scanf("%s %s",&a,&b);
        ^
./Main.c:13:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[107]’ [-Wformat=]
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s",&a,&b);
  ^