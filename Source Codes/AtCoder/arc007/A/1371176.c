#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,lon;
	char x;
	char s[51];
	scanf("%c %s",&x,s);
	
	lon=strlen(s);
	
	for(i=0;i<lon;i++){
		if(s[i]!=x){
			printf("%c",s[i]);
		}
	}
	
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %s",&x,s);
  ^