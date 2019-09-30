#include<stdio.h>
int main(){
	
	int A,B,i,j,k,count=0;
	scanf("%d%d",&A,&B);
	
	for(i=1;i<10;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				
				if(A<=10000*i+1000*j+100*k+10*j+i&&10000*i+1000*j+100*k+10*j+i<=B){
					count++;
				}
				
				
			}
			
		}
		
	}
	
	printf("\n%d\n\n",count);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&A,&B);
  ^