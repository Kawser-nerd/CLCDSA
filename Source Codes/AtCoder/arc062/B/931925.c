#include<stdio.h>
#include<stdlib.h>

int main(void){
	char s[131072];
	int g=0,p=0,i,n;
	scanf("%s",s);
	n=strlen(s);
	for(i=1;i<=n;i++){
		if(s[i] == 'g'){g++;}
		if(s[i] == 'p'){p++;}
	}
	printf("%d\n",(n/2)-p);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:4: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  n=strlen(s);
    ^
./Main.c:8:4: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:8:4: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^