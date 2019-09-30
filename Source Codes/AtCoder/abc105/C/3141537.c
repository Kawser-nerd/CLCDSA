#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
	int N,i=0,len;
	int ans[32]={0};
	scanf("%d",&N);
	if(N==0){printf("0");return 0;}
	while(N!=0){
		ans[i] = abs(N)%2;
		N -= ans[i]*pow(-1,i);
		N /= 2;
		i++;
	}
	len = i-1;	
	for(i=len;i>=0;i--) printf("%d",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^