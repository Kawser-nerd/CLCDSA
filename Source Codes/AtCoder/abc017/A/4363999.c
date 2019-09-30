#include <stdio.h>

int main(void)
{
	int sum,score[100],x[100];
	
	for(int i=1;i<7;i++){
		
		scanf("%d",&(score[i]));
		
	}
	
	for(int i=1;i<7;i++){
		
		if(i%2!=0){
			
			x[i]=score[i]*(double)score[i+1]/10;
			
		}
	}
	
	sum=x[1]+x[3]+x[5];
	
	printf("%d\n",sum);
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(score[i]));
   ^