#include<stdio.h>
#include<string.h>
char s[30];
int main(){
	gets(s);
	int len=strlen(s);
	int isok,temp;
	if(strcmp(s,"zyxwvutsrqponmlkjihgfedcba")==0){
		printf("-1");
		return 0;
	}
	
	if(len!=26){//???????????????????????????????? 
		for(int j='a';j<='z';j++){
			isok=1;
			for(int k=0;k<len;k++){
				if(s[k]==j){
					isok=0;
					break;
				}
			}
			if(isok){
				printf("%s%c\n",s,j);
				return 0;
			}
		}	
	}
	
	else{//???? 
		int j=25;
		int k;
		while(s[j-1]>s[j]){
			j--;
		}
		//???????????????????????????
		for(k=s[j-1]+1;k<='z';k++){
			isok=1;
			for(int l=0;l<j-1;l++){
				if(s[l]==k){
					isok=0;
					break;
				}
			}
			if(isok)break;
		}
		s[j]='\0';
		s[j-1]=k;
		puts(s);
		return 0;	
	} 
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
/tmp/cc1WaNK5.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets' function is dangerous and should not be used.