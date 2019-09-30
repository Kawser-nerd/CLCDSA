#include <stdio.h>
#include <string.h>
int main(void){
	char s[51];
	int i;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='o' && s[i]!='k' && s[i]!='u'){
			if(s[i]=='c' && s[i+1]=='h'){
				i++;
			}
			else break;
		}
	}
	if(strlen(s)!=i) printf("NO\n");
	else printf("YES\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^