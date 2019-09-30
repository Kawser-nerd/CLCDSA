#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long 

int main(int argc, char const *argv[]){
	int a,b;
	char op;
	scanf("%d %c %d",&a,&op,&b);
	if(op == '+')	printf("%d\n", a + b);
	else printf("%d\n", a - b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %c %d",&a,&op,&b);
  ^