#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i=0,c=0;
	char s[101]={0},t=0;
	for(i=0;i<2000;i++){
		scanf("%c",&t);
		if(t=='\n')break;
		if(t=='A')s[c++]='A';
		if(t=='L')s[c++]='<';
		if(t=='R')s[c++]='>';
	}
	for(i=0;i<c;i++){
		printf("%c",s[i]);
		if(i!=c-1)printf(" ");
	}
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&t);
   ^