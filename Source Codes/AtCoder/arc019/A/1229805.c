#include <stdio.h>
#include <string.h>
int main(void)
{
	int i,lon;
	char s[15];
	scanf("%s",s);
	lon=strlen(s);
	
	for(i=0;i<=lon-1;i++){
		if(s[i]=='O' || s[i]=='D'){
			s[i]='0';
		} else if(s[i]=='I'){
			s[i]='1';
		} else if(s[i]=='Z'){
			s[i]='2';
		} else if(s[i]=='S'){
			s[i]='5';
		} else if(s[i]=='B'){
			s[i]='8';
		}
	}
	
	for(i=0;i<=lon-1;i++){
		printf("%c",s[i]);
	}
	printf("\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^