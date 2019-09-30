#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long 

int main(int argc, char const *argv[]){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a == b && b == c)	printf("1\n");
	else if(a == b || a == c || b == c)	printf("2\n");
	else printf("3\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^