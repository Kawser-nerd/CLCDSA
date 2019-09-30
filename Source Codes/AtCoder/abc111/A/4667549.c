#include<stdio.h>
int main(void) {
	char a[4];
	int i;
	gets(a);
	for (i = 0; i < 3; i++) {
		if (a[i] == '1')
			printf("9");
		else
			printf("1");
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(a);
  ^
/tmp/ccKHccNA.o: In function `main':
Main.c:(.text.startup+0x22): warning: the `gets' function is dangerous and should not be used.