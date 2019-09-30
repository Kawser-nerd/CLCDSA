#include <stdio.h>
int main(void){
	char s[51];
	int i=0;
	scanf("%s",s);
	while(1){
		if(s[i]=='\0'){
			break;
		}
		i++;
	}
	if(s[i-1]=='T') printf("YES\n");
	else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^