#include<stdio.h>

int main(){
		char s[10],i;
		scanf("%s",s);
		for(i=0;s[i]!=0;i++){
				if(s[i]=='O')printf("0");
				else if(s[i]=='D')printf("0");
				else if(s[i]=='I')printf("1");
				else if(s[i]=='Z')printf("2");
				else if(s[i]=='S')printf("5");
				else if(s[i]=='B')printf("8");
				else printf("%c",s[i]);
		}puts("");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^