#include<stdio.h>

int main(){
		int i;
		char x,s[51];
		scanf("%c%s",&x,s);
		for(i=0;s[i]!=0;i++)if(s[i]!=x)printf("%c",s[i]);
		puts("");return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c%s",&x,s);
   ^