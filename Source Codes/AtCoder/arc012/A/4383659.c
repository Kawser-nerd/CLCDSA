#include<stdio.h>
#include<string.h>

int main(){
		char s[15];
		scanf("%s",s);
		if(strcmp(s,"Sunday")==0)puts("0");
		if(strcmp(s,"Monday")==0)puts("5");
		if(strcmp(s,"Tuesday")==0)puts("4");
		if(strcmp(s,"Wednesday")==0)puts("3");
		if(strcmp(s,"Thursday")==0)puts("2");
		if(strcmp(s,"Friday")==0)puts("1");
		if(strcmp(s,"Saturday")==0)puts("0");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^