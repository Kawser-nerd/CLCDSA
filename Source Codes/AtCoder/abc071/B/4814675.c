#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long 

int main(int argc, char const *argv[]){
	int alphabet[259] = { 0 };
	char str[100007];
	scanf("%s",str);
	for (int i = 0; i < strlen(str); ++i)	++alphabet[(int)str[i]];
	for (int i = 'a'; i <= 'z'; ++i)
	{
		if(alphabet[i] == 0){
			printf("%c\n", i);
			return 0;
		}
	}
	printf("None\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^