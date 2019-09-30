#include <stdio.h>
#include <string.h>
int main(void){
	char s[11];
	int i,v=0;
	for(i=0;i<12;i++){
		scanf("%s",s);
		if(strchr(s,'r')!=NULL) v++;
	}
	printf("%d\n",v);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^