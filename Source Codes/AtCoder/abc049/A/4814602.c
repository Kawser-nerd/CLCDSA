#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long 

int main(int argc, char const *argv[]){
	char string[] = "aiueo";
	char ch;
	scanf("%c",&ch);
	for (int i = 0; i < 5; ++i)
	{
		if(ch == string[i]){
			puts("vowel");
			return 0;
		}
	}
	puts("consonant");
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&ch);
  ^