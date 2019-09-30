#include <stdio.h>

int main(void){
	int s;
	
	scanf("%d",&s);
	
	int i=1;
	
	if(s==1||s==2){
		printf("4\n");
	}else{
		while(s!=4){
			if(s%2==0){
				s=s/2;
			}else{
				s=3*s+1;
		}
		
		i++;
		}
	
		printf("%d\n",i+3);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&s);
  ^