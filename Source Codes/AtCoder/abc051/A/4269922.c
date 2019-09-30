#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets(a);
	int m = strlen(a);
	int i,j;
	for(i = 0;i<m;i++)
	{
		if(a[i] != ',')
		{
			printf("%c",a[i]);
		}
		else if(a[i] == ',')
		{
			printf(" ");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(a);
  ^
/tmp/cclFutcG.o: In function `main':
Main.c:(.text.startup+0x1d): warning: the `gets' function is dangerous and should not be used.