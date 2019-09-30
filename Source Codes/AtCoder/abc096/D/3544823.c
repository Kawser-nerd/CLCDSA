#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	//?????
	int n;
	int i,j,k;
	int sosu[5010];
	int count;
	
	//????????
	scanf("%d",&n);
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	//(????)5000????????????
	for(i=0;i<5000;i++){
		sosu[i]=i+2;
	}
	sosu[5000]=0;
	i=0;
	while(sosu[i]!=0){
		j=i+1;
		k=i+1;
		while(sosu[j]!=0){
			if(sosu[j]%sosu[i]!=0){
				sosu[k]=sosu[j];
				k++;
			}
			j++;
		}
		i++;
	}
	
	
	
//	printf("??????\n");
	
	//??
	
	count=0;
	i=0;
	while(count<n){
		if(sosu[i]%10==1){
			printf("%d",sosu[i]);
			count++;
			if(count!=n) printf(" ");
		}
		i++;
	}
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^