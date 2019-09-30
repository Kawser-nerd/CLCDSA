#include<stdio.h>

int main(void) {
	char a[20];
	gets(a);
	printf("%ss\n",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(a);
  ^
/tmp/ccREWxNI.o: In function `main':
Main.c:(.text.startup+0x18): warning: the `gets' function is dangerous and should not be used.