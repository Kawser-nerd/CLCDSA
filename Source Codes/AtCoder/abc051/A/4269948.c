#include<stdio.h>
#include<string.h>
int main(){
	char s[30];
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]==','){
			s[i]=' ';
		}
	}
	puts(s);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
/tmp/cctl1joj.o: In function `main':
Main.c:(.text.startup+0x1c): warning: the `gets' function is dangerous and should not be used.