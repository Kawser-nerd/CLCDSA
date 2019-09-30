#include <stdio.h>
 
int main(){
	int N,S,T,W,i,sum=0,count=0;
	scanf("%d %d %d\n",&N,&S,&T);
	for(i=0;i<N;i++){
		scanf("%d",&W);
		sum += W;
		if(sum>=S && sum<=T) count++;
		else;
	}
 
	printf("%d\n",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d\n",&N,&S,&T);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&W);
   ^