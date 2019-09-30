#include<stdio.h>
int main(){
	
	int K,S,X,Y,Z,count=0;
	scanf("%d%d",&K,&S);
	
	for(Z=0;Z<=K;Z++){
		
		for(Y=0;Y<=K&&Y<=S-Z;Y++){
		
		
			if(0<=S-Z-Y&&S-Z-Y<=K){
		count++;
			}
		
		}
	}
	
	printf("\n%d\n\n",count);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&K,&S);
  ^