#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,lon;
	char s[11];
	scanf("%s",s);
	
	lon=strlen(s);
	
	for(i=0;i<lon;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			printf("%c",s[i]);
		}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^