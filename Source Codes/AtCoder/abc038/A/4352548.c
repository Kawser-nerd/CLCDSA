#include <stdio.h>

int main(void)

{
	char name[100];
	
	scanf("%s",name);
	
	int i=0;
	int count=0;
	
	while(name[i]!='\0'){
		i++;
	}
	
	if(name[i-1]=='T'){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",name);
  ^