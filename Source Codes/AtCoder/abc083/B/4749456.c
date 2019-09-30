#include<stdio.h>
int main(){
	
	int N,A,B,i,j,k,l,sum=0;
	scanf("%d%d%d",&N,&A,&B);
	
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				for(l=0;l<10;l++){
				
				if(1000*i+100*j+10*k+l<=N&&A<=i+j+k+l&&i+j+k+l<=B){
					sum=sum+1000*i+100*j+10*k+l;
				
				}
			}
		}
	}
	}
	
	if(N==10000){
		sum=sum+10000;
		
	}
	
	
	
	printf("\n%d\n\n",sum);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^