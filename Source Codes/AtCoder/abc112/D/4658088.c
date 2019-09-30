#include <stdio.h>
#include <stdlib.h>
int main(void){
	int N,M,ans=0,i;
	scanf("%d%d",&N,&M);
	for(i=1;i*i<=M;i++){
		if(M%i==0){
			int x=i,y=M/x;
			if(y >= N)ans = ans<x?x:ans;
			if(x >= N)ans = ans<y?y:ans;
		}
	}
	
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^