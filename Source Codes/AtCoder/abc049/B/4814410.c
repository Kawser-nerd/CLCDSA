#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long

int main(int argc, char const *argv[]){
	int h,w;
	int j = 0;
	char c[107][107] = {'\0'};
	scanf("%d%d",&h,&w);
	for (int i = 0; i < h; ++i)	scanf(" %s",c[i]);
	for (int i = 0; i < 2 * h; ++i)
	{
		if(i % 2 == 0 && i > 0)	++j;
		printf("%s\n",&c[j]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[107]’ [-Wformat=]
   printf("%s\n",&c[j]);
          ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:15:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i = 0; i < h; ++i) scanf(" %s",c[i]);
                              ^