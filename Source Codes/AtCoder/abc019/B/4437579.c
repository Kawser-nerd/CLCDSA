#include <stdio.h>
int main(void){
	int i,count=1;
	char s[1001],p[1];
	scanf("%s",s);
	p[0]=s[0];
	for(i=0;s[i]!='\0';i++){
		if(s[i]==s[i+1]){
			count++;
			continue;
		}
		printf("%c%d",p[0],count);
		count=1;
		p[0]=s[i+1];
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^