#include <stdio.h>

int main(void)
{
	char x,y,A,B,C,D,E,F;
	char s[]={A,B,C,D,E,F};
	
	scanf("%c %c",&x,&y);
	
	for(int i=0;i<6;i++){
		s[i]=i;
	}
	
	if(x>y){
		printf(">\n");
	}else if(x==y){
		printf("=\n");
	}else{
		printf("<\n");
	}
		
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&x,&y);
  ^