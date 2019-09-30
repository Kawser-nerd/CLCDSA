#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	//?????
	
	int n,k;
	int temp=0;
	long int ans=0;
	int i,j;
	
	//????????
	scanf("%d %d",&n,&k);
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=1;i<n+1;i++){
		if(i>=k){
			temp=(i-k)*(n/i);
			if(n%i-k+1>0){
				if(k==0){
					temp=temp+n%i-k;
				}else{
					temp=temp+n%i-k+1;
				}
			}
//			printf("i=%d temp=%d\n",i,temp);
		}else{
			temp=0;
		}
		ans=ans+temp;
	}
	
	
//	printf("??????\n");
	
	//??
	
	
	printf("%ld",ans);
	
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&k);
  ^