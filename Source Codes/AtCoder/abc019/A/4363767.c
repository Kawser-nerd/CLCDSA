#include <stdio.h>

int main(void)
{
	int a,b,c,count_1,count_2;
	int x[100];
	int max=-1;
	int min=200;
	int center=0;
	
	for(int i=0;i<3;i++){
		scanf("%d",&(x[i]));
	}
	
	for(int i=0;i<3;i++){
		
		if(x[i]>=max){
			max=x[i];
			count_1++;
		}
		
		if(x[i]<=min){
			min=x[i];
			count_2++;
		}
	}
	
	if(x[0]==x[1]&&x[1]==x[2]){
		printf("%d\n",x[0]);
	}else{
		for(int i=0;i<3;i++){
			if(x[i]==x[i+1]||x[i]==x[i+2]){
				printf("%d\n",x[i]);
			}else if(x[i]!=max&&x[i]!=min){
				printf("%d\n",x[i]);
		}
		}
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(x[i]));
   ^