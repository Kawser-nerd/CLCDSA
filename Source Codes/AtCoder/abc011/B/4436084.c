#include <stdio.h>
#include <string.h>
int main(void){
	int i=1;
	char s[13];
	gets(s);
	if(s[0]>'Z') s[0]-=0x20;
	while(s[i]!='\0'){
		if(s[i]<'a') s[i]+=0x20;
		i++;
	}
	puts(s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
/tmp/ccuWt2bi.o: In function `main':
Main.c:(.text.startup+0x18): warning: the `gets' function is dangerous and should not be used.