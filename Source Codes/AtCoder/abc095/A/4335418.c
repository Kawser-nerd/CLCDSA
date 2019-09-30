#include <stdio.h>

int main(void)
{
	int proper=700;
	char top[100];
	int i=0;
	scanf("%s", top);
	
	
	
	while(i<3){
		
		if(top[i]=='o'){
			proper=proper+100;
		}
		
		i++;
	}
	
	printf("%d\n",proper);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", top);
  ^