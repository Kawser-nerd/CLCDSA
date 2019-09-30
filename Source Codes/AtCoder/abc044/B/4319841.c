#include <stdio.h>
#include <string.h>

int main(void){
	char s[100];
	int i,j,len,flag=0;
	int tagi[26] = {0};
	scanf("%s",s);
	len = strlen(s);
	for(i=0;i<len;i++){
		for(j=0;j<26;j++){
			if('a' + j == s[i]){
				tagi[j]++;
			}
		}
	}
	for(i=0;i<26;i++){
		if(tagi[i]%2!=0){
			flag = 1;
		}
	}
	if(flag==1)printf("No\n");
	else printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^