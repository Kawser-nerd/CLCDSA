#include <stdio.h>
#include <string.h>
int main(void){
	int i=0;
	char s[13];
	gets(s);
	for(i=0;s[i]!='\0';i++){
		if(i==0){
			if(s[i]>'Z') s[i]-=0x20;
			continue;
		}
		else{
			if(s[i]<'a') s[i]+=0x20;
			continue;
		}
	}
	puts(s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
/tmp/ccd3Otp1.o: In function `main':
Main.c:(.text.startup+0x18): warning: the `gets' function is dangerous and should not be used.