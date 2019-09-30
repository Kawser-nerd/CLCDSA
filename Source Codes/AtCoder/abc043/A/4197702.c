#include<stdio.h>
int main(void){
	int N,a=0;
  	scanf("%d",&N);
  	for(int i=1;i<N+1;i++){
    	a+=i;
    }
  printf("%d\n",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&N);
    ^