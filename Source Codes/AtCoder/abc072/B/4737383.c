#include<stdio.h>
int main(void){
	
	char s[100000];
	scanf("%s",s);
	
	int i,len=strlen(s);
	
	
	
	if(len%2==0){
	for(i=0;i<len/2;i++){
		
		printf("%c",s[2*i]);
		
	}
	}else {
	
	for(i=0;i<len/2+1;i++){
		
		printf("%c",s[2*i]);
		
	}
	}	
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:12: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  int i,len=strlen(s);
            ^
./Main.c:7:12: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:7:12: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^