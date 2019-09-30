#include <stdio.h>

int main(void)
{
	char s[100];
	
	scanf("%s",s);
	
	int i=0;
	int min=1000;
	int x;
	
	while(s[i+2]!='\0'){
		
		x=(int)((s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0');
		
		if(x>753){
			x=x-753;
		}else{
			x=753-x;
		}
			
		if(min>x){
			min=x;
		}
		
		i++;
		
	}
	
	printf("%d\n",min);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^