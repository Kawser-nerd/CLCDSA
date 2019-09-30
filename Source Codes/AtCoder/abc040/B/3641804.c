#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	//?????
	int n;
	
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int min;
	//????????
	scanf("%d",&n);
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	if(n==1){
		printf("0");
		return 0;
	}
	
	ans=10000000;
	for(i=1;i<n;i++){
		temp1=n/i;
		temp2=abs(temp1-i)+n%i;
		if(temp2<ans) ans=temp2;
//		printf("temp1=%d,temp2=%d\n",temp1,temp2);
	}
	
	
//	printf("??????\n");
	//??
	
	printf("%d",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^