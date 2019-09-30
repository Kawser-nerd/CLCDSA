#include<stdio.h>

int main(){
		int i,e[2]={0},c=0;
		char s[11];
		scanf("%s",s);
		for(i=0;s[i]!=0;i++){
				if('0'<=s[i]&&'9'>=s[i])e[c++]=s[i]-'0';
		}
		for(i=0;i<c;i++)printf("%d",e[i]);
		puts("");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^