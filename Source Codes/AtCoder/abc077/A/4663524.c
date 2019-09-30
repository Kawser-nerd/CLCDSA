#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long 

int main(int argc, char const *argv[]){
	char c1[3],c2[3];
	scanf("%s %s",c1,c2);
	if(c1[0] == c2[2] && c1[1] == c2[1] && c1[2] == c2[0]) puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s",c1,c2);
  ^