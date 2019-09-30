#include <stdio.h>

int main(void)
{
	char s[100];
	int count=0;
	int char_num=0;
	
	scanf("%s",s);
	
	for(int i=0;s[i]!='\0';i++){
		for(int j=0;s[j]!='\0';j++){
			if(s[i]==s[j]){
				count++;
			}
		}
		char_num++;
	}
	
	if(count==char_num){
		printf("yes\n");
	}else{
		printf("no\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^