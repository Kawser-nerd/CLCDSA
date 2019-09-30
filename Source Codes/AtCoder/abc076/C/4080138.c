#include<stdio.h>
#include<string.h>
int main() {
	char s[51], t[51];
	gets(s);
	gets(t);
	int len_t = strlen(t);
	int len_s = strlen(s);
	if(len_t>len_s) {
		printf("UNRESTORABLE");
		return 0;
	}
	int i;
	//int flag = 0;
	for(i=len_s-len_t;i>=0;i--) {
		int j;
		int flag = 0;
		for(j=len_t-1;j>=0;j--) {//??????? 
			if(s[j+i]!=t[j] && s[j+i]!='?') {
				flag = 1;
				break;
			}
		}
		if(flag==0) {//????????????? 
			for(j=len_t-1;j>=0;j--) {
				s[j+i] = t[j];
			}
			break;
		}
		if(flag==1 && i == 0) {/////???????? 
			printf("UNRESTORABLE");
			return 0;
		}
	}//?????????????? 
	for(i=0;i<len_s;i++) {
		if(s[i]=='?') {
			s[i] = 'a';
		}
	}
	puts(s);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
/tmp/ccmar1SX.o: In function `main':
Main.c:(.text.startup+0x25): warning: the `gets' function is dangerous and should not be used.